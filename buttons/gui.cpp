#include "gui.h"

void guiInteraction(sf::Vector2i &mousePosition, sf::RenderWindow &window,
                    TGraph &graph, sf::Font &vertexFont, sf::Thread &algoThread,
                    size_t &startV,
                    ButtonContainer &buttons, TSample &book,
                    TextBoxContainer &textBoxes) {
    for (size_t buttonIndex = 0; buttonIndex < buttons.GetSize(); ++buttonIndex) {
        if (buttons.buttons_[buttonIndex].Contains(mousePosition)) {
            switch (buttonIndex) {
                case ButtonActions::ADD_VERTEX:
                    graph.AddVertex(sf::Vector2f(512, 300), vertexFont, graph.GetVertexesSize());
                    break;
                case ButtonActions::ADD_EDGE:
                    if (!textBoxes.textboxes_[TextBoxes::ADD_EDGE_FROM].GetString().empty() &&
                        !textBoxes.textboxes_[TextBoxes::ADD_EDGE_TO].GetString().empty()) {
                        size_t from = std::stoi(textBoxes.GetString(TextBoxes::ADD_EDGE_FROM));
                        size_t to = std::stoi(textBoxes.GetString(TextBoxes::ADD_EDGE_TO));
                        if (from < graph.GetVertexesSize() || to < graph.GetVertexesSize())
                            graph.AddEdge({from, to});
                    }
                    break;
                case ButtonActions::CLEAN_GRAPH:
                    graph.CleanGraph();
                    break;
                case ButtonActions::CLEAR_GRAPH:
                    graph.ClearGraph();
                    break;
                case ButtonActions::START_DFS:
                {
                    if (!textBoxes.GetString(TextBoxes::ALGO_DFS_FROM).empty())
                        startV = std::stoi(textBoxes.GetString(TextBoxes::ALGO_DFS_FROM));
                    if (startV < graph.GetVertexesSize())
                        algoThread.launch();
                }
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