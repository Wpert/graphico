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
#include "../bs_threadpool//BS_thread_pool_light.hpp"

class TWorkArea {
private:
    sf::RectangleShape area_;
public:
    TWorkArea(sf::Vector2f pos, sf::Vector2f size);

    void Render(sf::RenderWindow &window, TGraph &graph);
};

class TLogic {
public:
    TLogic(sf::Font font);

    void Render(sf::RenderWindow &mainWindow);

    void ReadInputs(sf::RenderWindow &mainWindow);

    void TakeMousePosition(sf::RenderWindow &mainWindow);

    TGraph mainGraph_;
private:
    void guiInteraction(sf::RenderWindow &window, Button &button);

    bool isMainWindowActive_ = true;

    sf::Vector2i mousePosition_;
    sf::Font mainFont_;
    ButtonContainer buttons_;
    TextBoxContainer textBoxes_;
    TWorkArea graphWorkspace_;
    TSample graphSamples_;

    TAlgo alg_;
    BS::thread_pool_light threadPool_;
};
#endif //FAV_GUI_H
