#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::RectangleShape
{
public:
	Ship(const sf::Vector2f& newSize, const sf::Vector2f& newPos,
		const sf::Color& newColor) :
		sf::RectangleShape(newSize)
	{
		this->setFillColor(newColor);
		this->setPosition(newPos);
		loaded = false;
	}
	bool getStatus();
	void setStatus(bool load);
private:
	bool loaded;
};


void callbackground(sf::RenderWindow &window, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer);
bool placeCarrier(Ship &Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window);
bool placeBattleship(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window);
bool placeCruiser(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window);
bool placeSubmarine(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window);
bool placeDestroyer(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window);

