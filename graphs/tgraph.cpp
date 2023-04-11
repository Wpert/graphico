#include "tgraph.h"

void TGraph::AddVertex(sf::Vector2f position, sf::Font &vertexFont, size_t number) {
    this->vertexes_.emplace_back(position, vertexFont, number);
}

void TGraph::AddEdge(TEdge newEdge) {
    if (newEdge.from_ == -1 || newEdge.to_ == -1) {
        return;
    }
    for (auto edge : this->edgeList_) {
        if (edge == newEdge) {
            return;
        }
    }
    this->edgeList_.emplace_back(newEdge);
}

void TGraph::RenderEdge(TEdge edge, sf::RenderWindow &window) {
    // take a center of vertex
    sf::Vector2f from_Position = this->vertexes_[edge.from_].GetCenterPosition();
    sf::Vector2f to_Position = this->vertexes_[edge.to_].GetCenterPosition();

    sf::Vertex line[] = {
            sf::Vertex(from_Position, defaultEdgeColor),
            sf::Vertex(to_Position, defaultEdgeColor)
    };

    window.draw(line, 3, sf::Lines);
}

void TGraph::RenderGraph(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
    // edges first and vertexes second
    for (size_t i = 0; i < this->edgeList_.size(); ++i) {
        this->RenderEdge(edgeList_[i], window);
    }

    for (auto & vertex : this->vertexes_) {
        vertex.Render(mousePosition, window);
    }
}

void TGraph::changeVertexColor(size_t vertexIndex, sf::Color colorValue) {
    this->vertexes_[vertexIndex].changeOutlineColor(colorValue);
}

void TGraph::AreaCollisions(sf::RectangleShape &area) {
    int left_border = area.getGlobalBounds().left + 10;
    int top_border = area.getGlobalBounds().top + 10;

    int height = area.getGlobalBounds().height - 20;
    int width = area.getGlobalBounds().width - 20;

    for (auto &vertex : this->vertexes_) {
        sf::Vector2f centerPos = vertex.GetCenterPosition();
        if (centerPos.x < left_border || centerPos.x > left_border + width) {
            float diff = ((int)centerPos.x - left_border) % width;
            vertex.SetPosition({(int)(centerPos.x - 2.0 * diff), (int)centerPos.y});
        }
        if (centerPos.y < top_border || centerPos.y > top_border + height) {
            float diff = ((int)centerPos.y - top_border) % height;
            vertex.SetPosition({(int)centerPos.x, (int)(centerPos.y - 2.0 * diff)});
        }
    }
}

void TGraph::CleanGraph() {
    for (size_t i = 0; i < this->vertexes_.size(); ++i) {
        this->changeVertexColor(i, defaultOutlineColor);
    }
}

void TGraph::ClearGraph() {
    this->edgeList_.clear();
    this->vertexes_.clear();
}

std::vector<std::vector<int>> TGraph::adjacencyList() {
    std::vector<std::vector<int>> tempList(this->vertexes_.size());
    for (auto edge : this->edgeList_) {
        tempList[edge.from_].push_back(edge.to_);
        tempList[edge.to_].push_back(edge.from_);
    }
    return tempList;
}

void TGraph::MouseMoveVertex(sf::Vector2i &mousePosition) {
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return;
    }

    for (auto &firstVertex : this->vertexes_) {
        // check if mouse moves it
        if (firstVertex.Contains(mousePosition)) {
            bool noCollisionFlag = true;

            for (auto &secondVertex : this->vertexes_) {
                if (firstVertex.CollisionCheck(secondVertex)) {
                    noCollisionFlag = false;
                    sf::Vector2f centerPos2 = secondVertex.GetCenterPosition();
                    sf::Vector2f centerPos1 = firstVertex.GetCenterPosition();
                    sf::Vector2f delta = centerPos1 - centerPos2;

                    if (fabs(delta.x) < 5 && fabs(delta.y) < 5) {
                        sf::Vector2f epsilon(rand() % 10, rand() % 10);
                        firstVertex.SetPosition( sf::Vector2i(centerPos1 + epsilon) );
                        secondVertex.SetPosition( sf::Vector2i(centerPos2 - epsilon) );
                    }
                    else
                        firstVertex.SetPosition(sf::Vector2i(centerPos1 + delta));
                }
            }

            if (noCollisionFlag) {
                firstVertex.SetPosition(mousePosition);
            }
        }
    }
}