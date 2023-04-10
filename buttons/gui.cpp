#include "gui.h"

void guiInteraction(sf::Vector2i &mousePosition, sf::RenderWindow &window,
                    TGraph &graph, sf::Font &vertexFont, sf::Thread &kek,
                    ButtonContainer &buttons, TSample &book) {
    for (size_t buttonIndex = 0; buttonIndex < buttons.GetSize(); ++buttonIndex) {
        if (buttons.buttons_[buttonIndex].Contains(mousePosition)) {
            switch (buttonIndex) {
                case ButtonActions::ADD_VERTEX:
                    graph.AddVertex(sf::Vector2f(512, 300), vertexFont, graph.GetVertexesSize());
                    break;
                case ButtonActions::ADD_EDGE:
                    graph.pickEdgeStage = 1;
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
                    graph = book.MakePentaGon(vertexFont);
                    break;
                case ButtonActions::GRAPH_BNTREE:
                    graph.ClearGraph();
                    graph = book.MakeBinaryTree(vertexFont);
                    break;
                default:
                    std::cout << "Kek!" << std::endl;
                    break;
            }
        }
    }
}

TWorkArea::TWorkArea(sf::Vector2f pos, sf::Vector2f size) {
    this->area_.setSize(size);
    this->area_.setPosition(pos);
    this->area_.setFillColor(vertexesAreaColor);
}

void TWorkArea::Render(sf::RenderWindow &window, TGraph &graph) {
    graph.AreaCollisions(this->area_);
    window.draw(this->area_);
}