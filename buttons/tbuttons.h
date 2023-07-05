#ifndef FAV_TBUTTONS_H
#define FAV_TBUTTONS_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../resources/tcolors.h"
#include <mutex>
#include <shared_mutex>

class Button {
private:
    sf::RectangleShape box_;
    sf::Text text_;
public:
    size_t enumNumber_;

    Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text,
           sf::Font &buttonFont,
           size_t number);
    ~Button() {
//        std::cout << "button has destroyed" << std::endl;
    }

    bool Contains(sf::Vector2i& mousePosition) const;
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
};

enum ButtonActions{
    ADD_VERTEX = 0,
    ADD_EDGE = 1,
    CLEAN_GRAPH = 2,
    CLEAR_GRAPH = 3,
    START_DFS = 4,
    START_BFS = 5,
    EXIT = 6,
    GRAPH_COMPLEX = 7,
    GRAPH_PNTGON = 8,
    GRAPH_BNTREE = 9
};

class ButtonContainer {
    mutable std::shared_mutex buttonMtx_;
public:
    std::vector<Button> buttons_;

    explicit ButtonContainer(sf::Font &buttonFont) {
        this->buttons_.emplace_back(sf::Vector2f(10, 10), sf::Vector2f(200, 30), "Add vertex", buttonFont, ADD_VERTEX);
        this->buttons_.emplace_back(sf::Vector2f(10, 45), sf::Vector2f(200, 30), "Add edge", buttonFont, ADD_EDGE);
        this->buttons_.emplace_back(sf::Vector2f(10, 115), sf::Vector2f(200, 30), "Clean graph", buttonFont, CLEAN_GRAPH);
        this->buttons_.emplace_back(sf::Vector2f(10, 150), sf::Vector2f(200, 30), "Clear graph", buttonFont, CLEAR_GRAPH);

        this->buttons_.emplace_back(sf::Vector2f(10, 220), sf::Vector2f(200, 30), "Start DFS", buttonFont, START_DFS);
        this->buttons_.emplace_back(sf::Vector2f(10, 255), sf::Vector2f(200, 30), "Start BFS", buttonFont, START_BFS);

        this->buttons_.emplace_back(sf::Vector2f(10, 360), sf::Vector2f(200, 30), "Exit", buttonFont, EXIT);

        this->buttons_.emplace_back(sf::Vector2f(10, 490), sf::Vector2f(200, 30), "Graph Complex", buttonFont, GRAPH_COMPLEX);
        this->buttons_.emplace_back(sf::Vector2f(10, 525), sf::Vector2f(200, 30), "Graph Pentagon", buttonFont, GRAPH_PNTGON);
        this->buttons_.emplace_back(sf::Vector2f(10, 560), sf::Vector2f(200, 30), "Graph Binary Tree", buttonFont, GRAPH_BNTREE);
    }

    size_t GetSize();
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
};

#endif //FAV_TBUTTONS_H
