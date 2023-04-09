#include "buttons/gui.h"

int main() {
    sf::Color backgroundColor(19, 16, 15, 255);
    sf::RenderWindow mainWindow(sf::VideoMode(1024, 600),
                                "Graphico",
                                sf::Style::Close);
    // icon settings
    sf::Image icon;
    if (!icon.loadFromFile("C:\\Users\\amoik\\Desktop\\fav\\resources\\final_icon.png")) {
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
    TGraph mainGraph;
    mainGraph.AddVertex({400, 200}, vertexFont, 228);
    TSample book;

    mainGraph = book.MakePentaGon(vertexFont);

    sf::Thread algoThread([&]() {
        dfsAlgo alg;
        alg.start(0, mainGraph);

        std::cout << "Hello world!" << std::endl;
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
                    guiInteraction(mousePosition, mainWindow,
                                  mainGraph, vertexFont, algoThread,
                                  buttons, book);

                    if (mainGraph.pickEdgeStage > 0) {
                        mainGraph.MouseAddEdge(mousePosition);
                    }
                }
            }
        }

        mainGraph.MouseMoveVertex(mousePosition);

        mainWindow.clear(backgroundColor);

        buttons.Render(mousePosition, mainWindow);
        mainGraph.RenderGraph(mousePosition, mainWindow);

        mainWindow.display();
    }

    std::cout << "It works !! XD" << std::endl;
    return 0;
}
