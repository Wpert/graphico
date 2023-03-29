#include "gui.h"
#include <iostream>

// uiButtons in "buttons.h"
// mainGraph in "tgraph.h"

sf::Color backgrColor(19, 16, 15, 255);
sf::RenderWindow mainWindow(sf::VideoMode(1024, 600),
                            "Graphico",
                            sf::Style::Close);

int main() {
    // icon settings
    sf::Image icon;
    if (!icon.loadFromFile("C:/Users/amoik/Desktop/Graphico/final_icon.png")) {
        std::cout << "load icon error" << std::endl;
    }
    mainWindow.setIcon(32, 32, icon.getPixelsPtr());

    // other settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mainWindow.setFramerateLimit(120);

    // objects
    sf::Vector2i mousePosition;
    TGraph mainGraph;
    mainGraph.AddVertex(sf::Vector2f(320, 220));
    mainGraph.AddVertex(sf::Vector2f(420, 120));
    mainGraph.AddEdge(TEdge(0, 1));

    // algo thread
    sf::Thread algoDFS([&]() {
        std::vector<bool> lol = StartDFS(0, mainGraph);
        for (auto i : lol) {
            std::cout << i << std::endl;
        }
    });

    // main cycle
    while (mainWindow.isOpen()) {

        sf::Event event;
        mousePosition = sf::Mouse::getPosition(mainWindow);

		while (mainWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
                mainWindow.close();
			}
            // quick time events as I got it right
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    ButtonInteraction(mousePosition, mainGraph, mainWindow, algoDFS);

                    if (pickEdgeStage > 0) {
                        mainGraph.MouseAddEdge(mousePosition);
                    }
                }
            }
		}

		mainGraph.MouseMoveVertex(mousePosition);

		mainWindow.clear(backgrColor);

		RenderButtons(mousePosition, mainWindow);

		mainGraph.RenderGraph(mousePosition, mainWindow);

		mainWindow.display();
    }

    std::cout << "It works !! XD" << std::endl;
    return 0;
}
