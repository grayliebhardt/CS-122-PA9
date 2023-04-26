#pragma once
#include <SFML/Graphics.hpp>		//SMFL graphics library import

class Ship : public sf::RectangleShape	//Create class based off of sfml rectangle base class
{
public:
	Ship(const sf::Vector2f& newSize, const sf::Vector2f& newPos) :		//Constructor
		sf::RectangleShape(newSize)
	{
		this->setPosition(newPos);
		loaded = false;
	}
	bool getStatus();			//Getter
	void setStatus(bool load);		//Setter
private:
	bool loaded;				//Status of ship loading
};

typedef enum shot {				//Shot result options
	hit,miss,invalid
};

class Shot : public sf::RectangleShape
{
public:
	Shot(const sf::Vector2f& newSize, const sf::Vector2f& newPos) :
		sf::RectangleShape(newSize)
	{
		this->setPosition(newPos);
		loaded = false;
	}
	
	bool getShotStatus();
	void setShotStatus(bool load);
private:
	bool loaded;
};


void callbackground(sf::RenderWindow &window, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::Sprite background);
bool placeCarrier(Ship &Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeBattleship(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeCruiser(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeSubmarine(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeDestroyer(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
void spawnOpponentShips(Ship opponentships[]);
void placeSingleOpponentShip(Ship& ship);
bool placeShot(Shot& targetShot, Shot& missShot, Shot& hitShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);

void gameWrapper(void);
