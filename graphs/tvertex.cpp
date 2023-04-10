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
    auto centerPos = static_cast<sf::Vector2i>(this->GetCenterPosition());
    // i need to calculate distance
    sf::Vector2i vect(mousePosition.x - centerPos.x, mousePosition.y - centerPos.y);
    double distance = std::sqrt(vect.x * vect.x + vect.y * vect.y);
    double radius = this->circle_.getRadius();
    // i dont need accuracy
    return distance <= radius;
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

sf::Vector2f TGraph::TVertex::GetCenterPosition() const {
    sf::Vector2f tempPosition = this->circle_.getPosition();
    tempPosition.x += 20;
    tempPosition.y += 20;
    return tempPosition;
}

bool TGraph::TVertex::CollisionCheck(TVertex &other) {
    if (this->vertexNumber_ == other.vertexNumber_)
        return false;
//    return this->circle_.getGlobalBounds().intersects(other.circle_.getGlobalBounds());
    auto centerPos1 = this->GetCenterPosition();
    auto centerPos2 = other.GetCenterPosition();
    sf::Vector2f vect(centerPos2.x - centerPos1.x, centerPos2.y - centerPos1.y);
    double dist = sqrt(vect.x * vect.x + vect.y * vect.y);

    return dist < 2.0 * this->circle_.getRadius();
}

void TGraph::TVertex::changeOutlineColor(sf::Color colorValue) {
    this->circle_.setOutlineColor(colorValue);
}
