#pragma once
#include <SFML/Graphics.hpp>
#ifndef GUI_H

//classes


/*class Popup {
public:
	Popup(std::wstring text, unsigned int type);
	~Popup();

private:

	sf::Color color;
}; /**/

// ------------------

class Button
{
public:
	Button(
		sf::Vector2f position,
		sf::Vector2f size,
		std::string text);

	const bool is_pressed() const;
	void update(sf::Vector2i mouse_position);

private:
	bool isPressed_;
	sf::RectangleShape buttonShape_;
	sf::Text buttonText_;
};

/// ------------------

class Point
{
public:
	Point(sf::Vector2f position, uint8_t number ,bool state);
	~Point();

	const bool is_pressed() const;
	void update(sf::Vector2i mouse_position, int press_releaseFlag);

	sf::Vector2f position;
	sf::Vector2f number;
	int maxNum = 1;
	bool state;
private:
	bool* bounds = new bool[maxNum];

	bool isPressed_;
	sf::CircleShape pointShape_;
	sf::Text pointText_;
};

class Point_handler
{
public:
	Point_handler(sf::Vector2f working_area);
	void add_point();
	void add_bound();
	~Point_handler();

private:

};

void gui();

void button_contanier();

#endif // !gui
