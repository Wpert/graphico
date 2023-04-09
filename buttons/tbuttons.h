#ifndef FAV_TBUTTONS_H
#define FAV_TBUTTONS_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../resources/tcolors.h"

class Button {
private:
    sf::RectangleShape box_;
    sf::Text text_;

public:
    Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text,
           sf::Font &buttonFont);
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
    EXIT = 5,
    GRAPH_PNTGON = 6,
    GRAPH_BNTREE = 7
};

class ButtonContainer {
public:
    std::vector<Button> buttons_;

    explicit ButtonContainer(sf::Font &buttonFont) {
        this->buttons_.emplace_back(sf::Vector2f(10, 10), sf::Vector2f(200, 30), "Add vertex", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 45), sf::Vector2f(200, 30), "Add edge", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 80), sf::Vector2f(200, 30), "Clean graph", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 115), sf::Vector2f(200, 30), "Clear graph", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 150), sf::Vector2f(200, 30), "Start DFS", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 185), sf::Vector2f(200, 30), "Exit", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 525), sf::Vector2f(200, 30), "Graph Pentagon", buttonFont);
        this->buttons_.emplace_back(sf::Vector2f(10, 560), sf::Vector2f(200, 30), "Graph Binary Tree", buttonFont);
    }

    size_t GetSize();
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
};

#endif //FAV_TBUTTONS_H
