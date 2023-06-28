#include "gui.h"

TWorkArea::TWorkArea(sf::Vector2f pos, sf::Vector2f size) {
    this->area_.setSize(size);
    this->area_.setPosition(pos);
    this->area_.setFillColor(vertexesAreaColor);
}

void TWorkArea::Render(sf::RenderWindow &window, TGraph &graph) {
    graph.AreaCollisions(this->area_);
    window.draw(this->area_);
}

TLogic::TLogic(sf::Font font)
        : mainFont_(font), buttons_(mainFont_),
          graphWorkspace_({220, 10}, {794, 580}),
          textBoxes_(mainFont_) {
    this->mainGraph_ = graphSamples_.MakeBinaryTree(mainFont_);
}

void TLogic::guiInteraction(sf::RenderWindow &window, sf::Thread &algoThread, size_t &startV, Button &button) {
    switch (button.enumNumber_) {
        case ButtonActions::ADD_VERTEX:
            mainGraph_.AddVertex(sf::Vector2f(512, 300), mainFont_, mainGraph_.GetVertexesSize());
            break;
        case ButtonActions::ADD_EDGE:
            if ( !textBoxes_.textboxes_[TextBoxes::ADD_EDGE_FROM].GetString().empty() &&
                 !textBoxes_.textboxes_[TextBoxes::ADD_EDGE_TO].GetString().empty() )
            {
                size_t from = std::stoi(textBoxes_.GetString(TextBoxes::ADD_EDGE_FROM));
                size_t to = std::stoi(textBoxes_.GetString(TextBoxes::ADD_EDGE_TO));
                if (from < mainGraph_.GetVertexesSize() || to < mainGraph_.GetVertexesSize())
                    mainGraph_.AddEdge({from, to});
            }
            break;
        case ButtonActions::CLEAN_GRAPH:
            mainGraph_.CleanGraph();
            break;
        case ButtonActions::CLEAR_GRAPH:
            mainGraph_.ClearGraph();
            break;
        case ButtonActions::START_DFS:
        {
            if (!textBoxes_.GetString(TextBoxes::ALGO_DFS_FROM).empty())
                startV = std::stoi(textBoxes_.GetString(TextBoxes::ALGO_DFS_FROM));
            if (startV < mainGraph_.GetVertexesSize())
                algoThread.launch();
        }
            break;
        case ButtonActions::EXIT:
            window.close();
            break;
        case ButtonActions::GRAPH_PNTGON:
            mainGraph_.ClearGraph();
            mainGraph_ = graphSamples_.MakePentaGon(mainFont_);
            break;
        case ButtonActions::GRAPH_BNTREE:
            mainGraph_.ClearGraph();
            mainGraph_ = graphSamples_.MakeBinaryTree(mainFont_);
            break;
        default:
            std::cout << "Kek!" << std::endl;
            break;
    }
}

void TLogic::Render(sf::RenderWindow &mainWindow) {
    if (isMainWindowActive_) {
        mainWindow.clear(backgroundColor);
        graphWorkspace_.Render(mainWindow, mainGraph_);

        textBoxes_.Render(mainWindow);

        mainGraph_.MouseMoveVertex(mousePosition_);
        buttons_.Render(mousePosition_, mainWindow);
        mainGraph_.RenderGraph(mousePosition_, mainWindow);

        mainWindow.display();
    }
}

void TLogic::TakeMousePosition(sf::RenderWindow &mainWindow) {
    mousePosition_ = sf::Mouse::getPosition(mainWindow);
}

void TLogic::ReadInputs(sf::RenderWindow &mainWindow, sf::Thread &algoThread, size_t &startV) {
    sf::Event event;
    while (mainWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mainWindow.close();
        }
        // quick time events as I got it right
        textBoxes_.TakeInput(mousePosition_, event);

        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            // define which button has clicked
            for (auto &button : this->buttons_.buttons_)
                if (button.Contains(mousePosition_))
                    guiInteraction(mainWindow, algoThread, startV, button);
        }

        // closed or open
        if (event.type == sf::Event::LostFocus) {
            isMainWindowActive_ = false;
        }
        else if (event.type == sf::Event::GainedFocus) {
            isMainWindowActive_ = true;
        }
    }
}