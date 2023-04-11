#include "buttons/gui.h"
#include "buttons/textbox.h"

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(1024, 600),
                                "Graphico",
                                sf::Style::Close);
    // icon settings
    sf::Image icon;
    if (!icon.loadFromFile("C:/Users/amoik/Desktop/project/graphico/resources/final_icon.png")) {
        std::cout << "load icon error" << std::endl;
    }
    mainWindow.setIcon(32, 32, icon.getPixelsPtr());

    // other settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mainWindow.setFramerateLimit(60);


    sf::Font buttonFont;
    buttonFont.loadFromFile("C:/Windows/Fonts/Calibri.ttf");
    sf::Font vertexFont;
    vertexFont.loadFromFile("C:/Windows/Fonts/Calibri.ttf");

    // objects
    sf::Vector2i mousePosition;

    ButtonContainer buttons(buttonFont);
    TWorkArea graphWorkspace({220, 10}, {794, 580});

    TGraph mainGraph;
    TSample book;
    mainGraph = book.MakePentaGon(vertexFont);

    dfsAlgo alg;
    // a "wheel", need to rewrite algos.h
    size_t startV = 0;
    sf::Thread algoThread([&]() -> void {
        alg.start(startV, mainGraph);
    });

    TextBoxContainer mainTextBox(buttonFont);

    bool isWindowActive = true;

    // main cycle
    while (mainWindow.isOpen()) {
        sf::Event event;
        mousePosition = sf::Mouse::getPosition(mainWindow);

        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mainWindow.close();
            }
            // quick time events as I got it right
            mainTextBox.TakeInput(mousePosition, event);

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                guiInteraction(mousePosition, mainWindow,
                               mainGraph, vertexFont, algoThread,
                               startV,
                               buttons, book, mainTextBox);
            }

            // closed or open
            if (event.type == sf::Event::LostFocus) {
                isWindowActive = false;
            }
            else if (event.type == sf::Event::GainedFocus) {
                isWindowActive = true;
            }
        }

        if (isWindowActive) {
            mainGraph.MouseMoveVertex(mousePosition);

            mainWindow.clear(backgroundColor);
            graphWorkspace.Render(mainWindow, mainGraph);

            mainTextBox.Render(mainWindow);
            buttons.Render(mousePosition, mainWindow);

            mainGraph.RenderGraph(mousePosition, mainWindow);

            mainWindow.display();
        }
    }

    std::cout << "It works !! XD" << std::endl;
    return 0;
}
