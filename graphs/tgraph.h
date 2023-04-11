#ifndef FAV_TGRAPH_H
#define FAV_TGRAPH_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../resources/tcolors.h"
#include <iostream>
#include <string>
#include <cmath>

class TGraph {
private:
//    const size_t MAX_VERTEX_COUNT = 70;

    class TVertex {
    private:

        sf::CircleShape circle_;
        sf::Text text_;

    public:
        size_t vertexNumber_;

        TVertex(sf::Vector2f position, sf::Font &vertexFont, size_t number);
        ~TVertex() {
//            std::cout << "vertex has destroyed" << std::endl;
        }

        bool Contains(sf::Vector2i& mousePosition) const;
        void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);

        void SetPosition(sf::Vector2i newPosition);
        sf::Vector2f GetCenterPosition() const;

        bool CollisionCheck(TVertex &other);

        void changeOutlineColor(sf::Color colorValue);
    };

    struct TEdge {
        size_t from_;
        size_t to_;

        TEdge(size_t from, size_t to) : from_(from)
                                , to_(to) {}

        bool operator==(TEdge second) const {
            return (this->from_ == second.from_ && this->to_ == second.to_) ||
                   (this->to_ == second.from_ && this->from_ == second.to_);
        }

        bool operator!=(TEdge second) const {
            return !(operator==(second));
        }
    };

    std::vector<TEdge> edgeList_;
    std::vector<TVertex> vertexes_;
public:
    int pickEdgeStage = 0;
    int newFrom = -1;
    int newTo = -1;

    TGraph() = default;
    ~TGraph() = default;

    size_t GetVertexesSize() {
        return this->vertexes_.size();
    }

    void AddVertex(sf::Vector2f position, sf::Font &vertexFont, size_t number);
    void AddEdge(TEdge newEdge);

    void RenderEdge(TEdge edge, sf::RenderWindow &window);
    void RenderGraph(sf::Vector2i &mousePosition, sf::RenderWindow &window);

    void changeVertexColor(size_t vertexIndex, sf::Color colorValue);
    void AreaCollisions(sf::RectangleShape &area);

    void CleanGraph();
    void ClearGraph();

    std::vector<std::vector<int>> adjacencyList();

    void MouseMoveVertex(sf::Vector2i &mousePosition);
};

#endif //FAV_TGRAPH_H
