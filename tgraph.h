#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

sf::Font vertexFont;

const sf::Color defaultVertexColor(19, 16, 15, 255);
const sf::Color activeVertexColor(69, 66, 65, 255);
const sf::Color defaultOutlineColor(246, 65, 108, 255);
const sf::Color activeOutlineColor(sf::Color::Cyan);
const sf::Color defaultEdgeColor(255, 222, 125, 255);
const sf::Color activeEdgeColor(0, 184, 169, 255);

int vertexSerialNumber = 0;

int pickEdgeStage = 0;
int newFrom = -1;
int newTo = -1;

class TVertex {
private:
	sf::CircleShape circle_;
	sf::Text text_;

public:
	int vertexNumber_;

    TVertex() {
        this->vertexNumber_ = vertexSerialNumber++;
    }

    explicit  TVertex(sf::Vector2f position) {
        // set global number
        this->vertexNumber_ = vertexSerialNumber++;

        this->circle_.setPosition(sf::Vector2f(position.x - 20, position.y - 20));
        this->text_.setPosition(sf::Vector2f(position.x - 5, position.y - 12));

        this->circle_.setFillColor(defaultVertexColor);
        this->text_.setFillColor(defaultTextColor);

        this->circle_.setRadius(20);
        this->circle_.setOutlineThickness(3);
        this->circle_.setOutlineColor(defaultOutlineColor);

        // set text parameters
        this->text_.setCharacterSize(18);

        if (!vertexFont.loadFromFile("C:/Windows/Fonts/Calibri.ttf")) {
            std::cout << "Vertex doesnt have its font" << std::endl;
        }
        this->text_.setFont(vertexFont);

        this->text_.setString(std::to_string(this->vertexNumber_));
    }

	~TVertex() = default;

	bool Contains(sf::Vector2i& mousePosition) const {
	    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
        return this->circle_.getGlobalBounds().contains(tempPosition);
	}

	void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
        if (this->Contains(mousePosition)) {
            this->circle_.setFillColor(activeVertexColor);
        }
        else {
            this->circle_.setFillColor(defaultVertexColor);
        }

        window.draw(this->circle_);
        window.draw(this->text_);
    }

    void SetPosition(sf::Vector2i newPosition) {
        this->circle_.setPosition(newPosition.x - 20, newPosition.y - 20);
        this->text_.setPosition(newPosition.x - 5, newPosition.y - 12);
    }

    bool CollisionCheck(TVertex &other) {
        if (this->vertexNumber_ == other.vertexNumber_)
            return false;
        return this->circle_.getGlobalBounds().intersects(other.circle_.getGlobalBounds());
    }

    void changeOutlineColor(sf::Color colorValue) {
        this->circle_.setOutlineColor(colorValue);
    }

    sf::Vector2f GetCenterPosition() {
        sf::Vector2f tempPosition = this->circle_.getPosition();
        tempPosition.x += 20;
        tempPosition.y += 20;
        return tempPosition;
    }
};

struct TEdge {
    int from_;
    int to_;

    TEdge(int from, int to) : from_(from)
                            , to_(to) {}

    bool operator==(TEdge second) const {
        return (this->from_ == second.from_ && this->to_ == second.to_) ||
                (this->to_ == second.from_ && this->from_ == second.to_);
    }

    bool operator!=(TEdge second) const {
        return !(operator==(second));
    }
};

class TGraph {
private:
    std::vector<TEdge> edgeList_;
    std::vector<TVertex> vertexes_;

public:
    TGraph() = default;
    ~TGraph() = default;

    void AddVertex(sf::Vector2f position) {
        this->vertexes_.emplace_back(position);
    }

    void AddEdge(TEdge newEdge) {
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

    void RenderEdge(TEdge edge, sf::RenderWindow &window) {
        // take a center of vertex
        sf::Vector2f from_Position = this->vertexes_[edge.from_].GetCenterPosition();
        sf::Vector2f to_Position = this->vertexes_[edge.to_].GetCenterPosition();

        sf::Vertex line[] = {
            sf::Vertex(from_Position, defaultEdgeColor),
            sf::Vertex(to_Position, defaultEdgeColor)
        };

        window.draw(line, 3, sf::Lines);
    }

    void CleanGraph() {
        for (size_t i = 0; i < this->vertexes_.size(); ++i) {
            this->changeVertexColor(i, defaultOutlineColor);
        }
    }

    void ClearGraph() {
        vertexSerialNumber = 0;
        this->edgeList_.clear();
        this->vertexes_.clear();
    }

    void RenderGraph(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
        // edges first and vertexes second
        for (size_t i = 0; i < this->edgeList_.size(); ++i) {
            this->RenderEdge(edgeList_[i], window);
        }

        for (auto vertex : this->vertexes_) {
            vertex.Render(mousePosition, window);
        }
    }

    std::vector<std::vector<int>> adjacencyList() {
        std::vector<std::vector<int>> tempList(this->vertexes_.size());
        for (auto edge : this->edgeList_) {
            tempList[edge.from_].push_back(edge.to_);
            tempList[edge.to_].push_back(edge.from_);
        }
        return tempList;
    }

    void changeVertexColor(size_t vertexIndex, sf::Color colorValue) {
        this->vertexes_[vertexIndex].changeOutlineColor(colorValue);
    }

    void MouseMoveVertex(sf::Vector2i &mousePosition) {
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

    void MouseAddEdge(sf::Vector2i &mousePosition) {
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
    // the end
};
