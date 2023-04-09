#ifndef FAV_GUI_H
#define FAV_GUI_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphs/tgraph.h"
#include "tbuttons.h"
#include "../resources/tsample.h"
#include "../algo/algos.h"

void guiInteraction(sf::Vector2i &mousePosition, sf::RenderWindow &window,
                    TGraph &graph, sf::Font &vertexFont, sf::Thread &kek,
                    ButtonContainer &buttons, TSample &book);

void EventProcessing();

#endif //FAV_GUI_H
