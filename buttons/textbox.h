#ifndef GRAPHICO_TEXTBOX_H
#define GRAPHICO_TEXTBOX_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../resources/tcolors.h"
#include <string>

class TextBox {
    sf::RectangleShape box_;
    sf::Text text_;
    std::string inputText_;
    bool focus_;
public:
    TextBox(sf::Vector2f position,
            sf::Vector2f size,
            sf::Font &buttonFont);
    ~TextBox() = default;

    bool Contains(sf::Vector2i& mousePosition);
    void TakeInput(sf::Vector2i& mousePosition, sf::Event &event);
    void Render(sf::RenderWindow &window);
    std::string GetString();
};

class TextBoxContainer {
public:
    std::vector<TextBox> textboxes_;
    std::vector<sf::Text> names_;

    explicit TextBoxContainer(sf::Font &buttonFont) {
        this->textboxes_.emplace_back(sf::Vector2f(65, 80), sf::Vector2f(45, 30), buttonFont);
        this->textboxes_.emplace_back(sf::Vector2f(165, 80), sf::Vector2f(45, 30), buttonFont);
        this->textboxes_.emplace_back(sf::Vector2f(165, 220), sf::Vector2f(45, 30), buttonFont);

        sf::Text textAddEdgeFrom("From:", buttonFont, 18);
        textAddEdgeFrom.setPosition({10 + 5, 80 + 5});
        sf::Text textAddEdgeTo("To:", buttonFont, 18);
        textAddEdgeTo.setPosition({115 + 5, 80 + 5});
        sf::Text textDFSFrom("From:", buttonFont, 18);
        textDFSFrom.setPosition({10 + 5, 220 + 5});

        this->names_.push_back(textAddEdgeFrom);
        this->names_.push_back(textAddEdgeTo);
        this->names_.push_back(textDFSFrom);
    }

    size_t GetSize() {
        return this->textboxes_.size();
    }
    std::string GetString(size_t num);
    void TakeInput(sf::Vector2i& mousePosition, sf::Event &event);
    void Render(sf::RenderWindow &window);
};

enum TextBoxes {
    ADD_EDGE_FROM = 0,
    ADD_EDGE_TO = 1,
    ALGO_DFS_FROM = 2,
    ALGO_BFS_FROM = 3
};

#endif //GRAPHICO_TEXTBOX_H
