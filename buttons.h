#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

sf::Font buttonFont;

sf::Color defaultButtonColor(30, 27, 26, 255);
sf::Color activeButtonColor(69, 66, 65, 255);
sf::Color defaultTextColor(200,210,200,255);

class Button {
	sf::RectangleShape box_;
	sf::Text text_;

public:
	Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text) {

        this->box_.setSize(size);

        {
            this->box_.setPosition(position);
            sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
            this->text_.setPosition(tempPosition);
        }

        this->box_.setFillColor(defaultButtonColor);
        this->text_.setFillColor(defaultTextColor);

        this->text_.setCharacterSize(18);

        {
            if (!buttonFont.loadFromFile("C:/Windows/Fonts/Calibri.ttf")) {
                std::cout << "Button doesnt have its font" << std::endl;
            }
            this->text_.setFont(buttonFont);
        }

        this->text_.setString(text);
    }

    ~Button() = default;

	bool Contains(sf::Vector2i& mousePosition) const {
	    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
        return this->box_.getGlobalBounds().contains(tempPosition);
	}

    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
        if (this->Contains(mousePosition)) {
            this->box_.setFillColor(activeButtonColor);
        }
        else {
            this->box_.setFillColor(defaultButtonColor);
        }

        window.draw(this->box_);
        window.draw(this->text_);
	}
};

std::vector<Button> uiButtons = {
    Button(sf::Vector2f(10, 10), sf::Vector2f(200, 30), "Add vertex"),
    Button(sf::Vector2f(10, 45), sf::Vector2f(200, 30), "Add edge"),
    Button(sf::Vector2f(10, 80), sf::Vector2f(200, 30), "Clean graph"),
    Button(sf::Vector2f(10, 115), sf::Vector2f(200, 30), "Clear graph"),
    Button(sf::Vector2f(10, 150), sf::Vector2f(200, 30), "Start DFS"),
    Button(sf::Vector2f(10, 185), sf::Vector2f(200, 30), "Exit"),
    Button(sf::Vector2f(10, 525), sf::Vector2f(200, 30), "Graph Pentagon"),
    Button(sf::Vector2f(10, 560), sf::Vector2f(200, 30), "Graph Binary Tree")
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

void RenderButtons(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
    for (auto button : uiButtons) {
        button.Render(mousePosition, window);
    }
}