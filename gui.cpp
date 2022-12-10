#include "gui.h"
#include <string>
#include <iostream>

/// параметры окна
sf::RenderWindow window (sf::VideoMode(1024, 600), "Graphico", sf::Style::Close);

/// цвета интерфейса
sf::Color background_c(19, 16, 15, 255);
sf::Color element_c(30, 27, 26, 255);
sf::Color element_active_c(69, 66, 65, 255);
sf::Color text_c(200,210,200,255);
sf::Color point_c(sf::Color::Magenta);
sf::Color line_c(50, 50, 50, 255);
sf::Color highlight_c(80, 80, 80, 255);

/// шрифт интерфейса
sf::Font font;

/// класс Button
Button::Button(sf::Vector2f position,
               sf::Vector2f size_value,
               std::string text_value)
               : buttonShape_(size_value)
               , buttonText_(text_value, font, 22)
               , isPressed_(false)
{
    // зададим цвет и позицию каждому элементу
	this->buttonShape_.setFillColor(element_c);
	this->buttonShape_.setPosition(position);

	this->buttonText_.setPosition(sf::Vector2f(position.x + 5, position.y + 5));
	this->buttonText_.setFillColor(text_c);
}

const bool Button::is_pressed() const {
	return this->isPressed_;
}

void Button::update(sf::Vector2i mouse_position) {
	this->isPressed_ = false;
	if (this->buttonShape_.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_position))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->isPressed_ = true;
		this->buttonShape_.setFillColor(element_active_c);
	}
	else {
		this->isPressed_ = false;
		this->buttonShape_.setFillColor(element_c);
	}

	window.draw(this->buttonShape_);
	window.draw(this->buttonText_);
}

/// класс Point

Point::Point(sf::Vector2f position,
             uint8_t number,
             bool state)
            : isPressed_(state)
            , pointShape_(20, 12)
            , pointText_(std::to_string(number), font, 22)
{
    // задаем цвета и позицию
	this->pointText_.setFillColor(text_c);
	this->pointText_.setPosition(sf::Vector2f(position.x + 10,
                                              position.y + 4));

	this->pointShape_.setPosition(position);
	this->pointShape_.setFillColor(background_c);
	this->pointShape_.setOutlineThickness(3);
	this->pointShape_.setOutlineColor(point_c);
}

Point::~Point() {
    delete[] bounds;
}

const bool Point::is_pressed() const{
	return this->isPressed_;
}

void Point::update(sf::Vector2i mouse_position,
                   int press_releaseFlag)
{
    std::cout << (this->isPressed_ ? "true\n" : "false\n");

	if (this->pointShape_.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_position))
		&& press_releaseFlag == 1) {
		this->isPressed_ = true;
	}

	else if (press_releaseFlag == 2) {
		this->isPressed_ = false;
		pointShape_.setFillColor(element_c);
	}

	if(this->isPressed_) {
        pointShape_.setFillColor(element_active_c);
		pointShape_.setPosition(sf::Vector2f(mouse_position.x - 20,
                                             mouse_position.y - 20));
		pointText_.setPosition(sf::Vector2f(mouse_position.x - 10,
                                            mouse_position.y - 16));
	}

	window.draw(pointShape_);
	window.draw(pointText_);
}

/// основное окно

void gui() {
	sf::Clock clock;
	Point point(sf::Vector2f(400, 400), 1, false);
	window.setFramerateLimit(60);

	if (!font.loadFromFile("calibri.ttf")) {
		std::cout << "Couldn`t find font.\n";
	}

	sf::Vector2i MousePos;
	Button button(sf::Vector2f(0, 0), sf::Vector2f(50, 50), "f");

	while (window.isOpen()) {
		sf::Event event;

		window.clear(background_c);
		button_contanier();
		MousePos = sf::Mouse::getPosition(window);

        point.update(MousePos, 0);

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
                std::cout << "\nClose button pressed.\n";
                window.close();
			}

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    std::cout << "\nEscape button pressed.\n";
                    window.close();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    point.update(MousePos, 1);
                    std::cout << "LCM!\n";
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    point.update(MousePos, 2);
                    std::cout << "LCM.\n";
                }
            }
		}

		if (button.is_pressed())
			std::cout << "Current fps: " << 1.f / clock.getElapsedTime().asSeconds() << "\n";
		clock.restart();
		window.display();
	}
}




// functions
bool main_window() {
	return 0;
}

// ------------------------

void button_contanier() {
	Button buttons[5]{
	    /// Button(position, size, text);
        Button(sf::Vector2f(0, 0), sf::Vector2f(190, 30), "Добавить Вершину"),
        Button(sf::Vector2f(0, 30), sf::Vector2f(90, 30), "button 2"),
        Button(sf::Vector2f(0, 60), sf::Vector2f(90, 30), "button 3"),
        Button(sf::Vector2f(0, 90), sf::Vector2f(90, 30), "button 4"),
        Button(sf::Vector2f(0, 120), sf::Vector2f(90, 30), "button 5"),
	};

	for (int i = 0; i < 5; ++i) {
		buttons[i].update(sf::Mouse::getPosition(window));
		if (buttons[i].is_pressed()) {
			switch (i + 1)
			{
			case 1:
				std::cout << "Добавка вершины\n";
				//do button 1 things
				break;
			case 2:
				std::cout << "butto...i'm too lazy to complite this\n";
				//do button 2 things
				break;
			case 3:
				//do button 2 things
				break;
			case 4:
				//do button 2 things
				break;
			case 5:
				//do button 2 things
				break;
			}

		}

	}
}
