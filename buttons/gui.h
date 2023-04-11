#ifndef FAV_GUI_H
#define FAV_GUI_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphs/tgraph.h"
#include "tbuttons.h"
#include "../resources/tsample.h"
#include "../resources/tcolors.h"
#include "../algo/algos.h"
#include "textbox.h"

void guiInteraction(sf::Vector2i &mousePosition, sf::RenderWindow &window,
                    TGraph &graph, sf::Font &vertexFont, sf::Thread &algoThread,
                    size_t &startV,
                    ButtonContainer &buttons, TSample &book,
                    TextBoxContainer &textBoxes);

class TWorkArea {
private:
    sf::RectangleShape area_;
public:
    TWorkArea(sf::Vector2f pos, sf::Vector2f size);

    void Render(sf::RenderWindow &window, TGraph &graph);
};
#endif //FAV_GUI_H
