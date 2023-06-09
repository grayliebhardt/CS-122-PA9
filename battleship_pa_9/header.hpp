#pragma once
#include <SFML/Graphics.hpp>		//SMFL graphics library import
#define Max_Main_Menu 4			//Define main menu

class Ship : public sf::RectangleShape	//Create class based off of sfml rectangle base class
{
public:
	Ship(const sf::Vector2f& newSize, const sf::Vector2f& newPos) :		//Constructor
		sf::RectangleShape(newSize)
	{
		this->setPosition(newPos);
		loaded = false;
	}
	~Ship(){}				//Destructor
	
	bool getStatus();			//Getter
	void setStatus(bool load);		//Setter
private:
	bool loaded;				//Status of ship loading
};

//Created class for the Main Menu 
class MainMenu 
{
public:

	MainMenu(float width, float height);	//Constructor

	//Functions for Class
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~MainMenu();				//Destructor

private:
	int MainMenuSelected;			//Menu selection
	sf::Font font;				//Font
	sf::Text mainMenu[Max_Main_Menu];	
};

typedef enum shot {				//Shot result options
	hit,miss,invalid
};

class Shot : public sf::RectangleShape		//Shot class that inherits from sfml rectangle shape base class
{
public:
	Shot(const sf::Vector2f& newSize, const sf::Vector2f& newPos) :		//Constructor
		sf::RectangleShape(newSize)
	{
		this->setPosition(newPos);
		loaded = false;
	}
	~Shot(){};								//Destructor
	
	bool getShotStatus();		//Getter
	void setShotStatus(bool load);	//Setter
private:
	bool loaded;			//status
};

//Functions
void callbackground(sf::RenderWindow &window, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::Sprite background);
bool placeCarrier(Ship &Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeBattleship(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeCruiser(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeSubmarine(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
bool placeDestroyer(Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
void spawnOpponentShips(Ship opponentships[]);
void placeSingleOpponentShip(Ship& ship);
bool placeShot(int& hits, Shot& targetShot, Shot& missShot, Shot& hitShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background);
//Game wrapper
void gameWrapper(void);
