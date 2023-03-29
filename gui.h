#pragma once
#include "buttons.h"
#include "tgraph.h"
#include "sample.h"
#include "algos.h"

void ButtonInteraction(sf::Vector2i &mousePosition,
                       TGraph &graph,
                       sf::RenderWindow &window,
                       sf::Thread &kek) {
    for (size_t buttonIndex = 0; buttonIndex < uiButtons.size(); ++buttonIndex) {
        if (uiButtons[buttonIndex].Contains(mousePosition)) {
            switch (buttonIndex) {
                case ButtonActions::ADD_VERTEX:
                    graph.AddVertex(sf::Vector2f(512, 300));
                    break;
                case ButtonActions::ADD_EDGE:
                    pickEdgeStage = 1;
                    break;
                case ButtonActions::CLEAN_GRAPH:
                    graph.CleanGraph();
                    break;
                case ButtonActions::CLEAR_GRAPH:
                    graph.ClearGraph();
                    break;
                case ButtonActions::START_DFS:
                    kek.launch();
                    break;
                case ButtonActions::EXIT:
                    window.close();
                    break;
                case ButtonActions::GRAPH_PNTGON:
                    graph.ClearGraph();
                    graph = MakePentaGon();
                    break;
                case ButtonActions::GRAPH_BNTREE:
                    graph.ClearGraph();
                    graph = MakeBinaryTree();
                    break;
                default:
                    std::cout << "Kek!" << std::endl;
                    break;
            }
        }
    }
}
