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
    TLogic mainObjects(font);

    // main cycle
    while (mainWindow.isOpen()) {
        mainObjects.TakeMousePosition(mainWindow);
        // user devices
        mainObjects.ReadInputs(mainWindow);
        // rendering
        mainObjects.Render(mainWindow);
    }

    return 0;
}
