#include "buttons/gui.h"
#include "buttons/textbox.h"

std::string getDirPath() {
    std::string path(__FILE__);
    path = path.substr(0, path.rfind('\\') + 1);
    for (auto &chr : path) {
        if (chr == '\\')
            chr = '/';
    }
    return path;
}

int main() {
    // render-window settings
    sf::RenderWindow mainWindow(sf::VideoMode(1024, 600),
                                "Graphico",
                                sf::Style::Close);

    std::string dirPath = getDirPath();

    // icon settings
    sf::Image icon;
    if (!icon.loadFromFile(dirPath + "resources/final_icon.png")) {
        std::cout << "load icon error" << std::endl;
    }
    mainWindow.setIcon(32, 32, icon.getPixelsPtr());

    // other settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mainWindow.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile(dirPath + "resources/calibri.ttf");

    // objects
    TLogic mainK(font);

    std::thread takeMousePos([&](){
        while (mainWindow.isOpen())
            mainK.TakeMousePosition(mainWindow);
    });

    // main cycle
    while (mainWindow.isOpen()) {
        // user devices
        mainK.ReadInputs(mainWindow);
        // rendering
        mainK.Render(mainWindow);
    }

    takeMousePos.join();
    std::cout << "my work here is done." << std::endl;
    return 0;
}
