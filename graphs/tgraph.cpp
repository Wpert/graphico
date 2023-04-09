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
        if (firstVertex.Contains(mousePosition)) {
            bool noCollisionFlag = true;
            for (auto &secondVertex : this->vertexes_) {
                if (firstVertex.CollisionCheck(secondVertex)) {
                    noCollisionFlag = false;
                    sf::Vector2f v1 = secondVertex.GetCenterPosition();
                    sf::Vector2f v2 = firstVertex.GetCenterPosition();
                    sf::Vector2f delta = v2 - v1;
                    int kek = std::rand() % 5;
                    delta = sf::Vector2f(delta.x / 3 + kek, delta.y / 3 + kek);
                    firstVertex.SetPosition(sf::Vector2i(v2 + delta));
                }
            }
            if (noCollisionFlag) {
                firstVertex.SetPosition(mousePosition);
            }
        }
    }
}

void TGraph::MouseAddEdge(sf::Vector2i &mousePosition) {
    if (pickEdgeStage == 1) {
        for (size_t i = 0; i < this->vertexes_.size(); ++i) {
            if (this->vertexes_[i].Contains(mousePosition)) {
                newFrom = (int) i;
                pickEdgeStage = 2;
            }
        }
    }
    else if (pickEdgeStage == 2) {
        for (size_t i = 0; i < this->vertexes_.size(); ++i) {
            if (newFrom != (int) i && this->vertexes_[i].Contains(mousePosition)) {
                newTo = (int) i;
                this->AddEdge(TEdge(newFrom, newTo));
                newTo = -1;
                newFrom = -1;
                pickEdgeStage = 0;
            }
        }
    }
}