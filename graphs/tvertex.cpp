#include "tgraph.h"

TGraph::TVertex::TVertex(sf::Vector2f position, sf::Font &vertexFont, size_t number) {
    // set global number
    this->vertexNumber_ = number;
//    std::cout << number << std::endl;

    this->circle_.setPosition(sf::Vector2f(position.x - 20, position.y - 20));
    this->text_.setPosition(sf::Vector2f(position.x - 5, position.y - 12));

    this->circle_.setFillColor(defaultVertexColor);
    this->text_.setFillColor(defaultTextVertexColor);

    this->circle_.setRadius(20);
    this->circle_.setOutlineThickness(3);
    this->circle_.setOutlineColor(defaultOutlineColor);

    // set text parameters
    this->text_.setCharacterSize(18);
    this->text_.setFont(vertexFont);

    this->text_.setString(std::to_string(this->vertexNumber_));
}

bool TGraph::TVertex::Contains(sf::Vector2i &mousePosition) const {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->circle_.getGlobalBounds().contains(tempPosition);
}

void TGraph::TVertex::Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
    if (this->Contains(mousePosition)) {
        this->circle_.setFillColor(activeVertexColor);
    }
    else {
        this->circle_.setFillColor(defaultVertexColor);
    }

    window.draw(this->circle_);
    window.draw(this->text_);
}

void TGraph::TVertex::SetPosition(sf::Vector2i newPosition) {
    this->circle_.setPosition(newPosition.x - 20, newPosition.y - 20);
    this->text_.setPosition(newPosition.x - 5, newPosition.y - 12);
}

sf::Vector2f TGraph::TVertex::GetCenterPosition() {
    sf::Vector2f tempPosition = this->circle_.getPosition();
    tempPosition.x += 20;
    tempPosition.y += 20;
    return tempPosition;
}

bool TGraph::TVertex::CollisionCheck(TVertex &other) {
    if (this->vertexNumber_ == other.vertexNumber_)
        return false;
    return this->circle_.getGlobalBounds().intersects(other.circle_.getGlobalBounds());
}

void TGraph::TVertex::changeOutlineColor(sf::Color colorValue) {
    this->circle_.setOutlineColor(colorValue);
}
