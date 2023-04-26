#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::RectangleShape
{
public:
	Ship(const sf::Vector2f& newSize, const sf::Vector2f& newPos) :
		sf::RectangleShape(newSize)
	{
		this->setPosition(newPos);
		loaded = false;
	}
	bool getStatus();
	void setStatus(bool load);
private:
	bool loaded;
};

typedef enum shot {
	hit,miss,invalid
};

void callbackground(sf::RenderWindow &window, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::Sprite background);
bool placeCarrier(Ship &Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeBattleship(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeCruiser(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeSubmarine(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeDestroyer(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
void spawnOpponentShips(Ship opponentships[]);
void placeSingleOpponentShip(Ship& ship);
