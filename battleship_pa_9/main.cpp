#include "header.hpp"

int main(void)
{
	//Render background
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Battleship");
	Ship Carrier(sf::Vector2f(30, 230), sf::Vector2f(60, 110)), Battleship(sf::Vector2f(30, 180), sf::Vector2f(60, 110)), Cruiser(sf::Vector2f(30, 130), sf::Vector2f(60, 110)), Submarine(sf::Vector2f(30, 130), sf::Vector2f(60, 110)), Destroyer(sf::Vector2f(30, 80), sf::Vector2f(60, 110));
	Shot targetShot(sf::Vector2f(30, 30), sf::Vector2f(660, 110)), hitShip(sf::Vector2f(30, 30), sf::Vector2f(60, 110)), missShip(sf::Vector2f(30, 30), sf::Vector2f(60, 110));
	sf::Event event;
	sf::Texture carTexture, batTexture, cruTexture, subTexture, desTexture;
	sf::Texture ocean;
	ocean.loadFromFile("ocean.jpg");
	sf::Sprite background(ocean);
	carTexture.loadFromFile("carrier.png");
	Carrier.setTexture(&carTexture);
	batTexture.loadFromFile("battleship.png");
	Battleship.setTexture(&batTexture);
	cruTexture.loadFromFile("cruiser.png");
	Cruiser.setTexture(&cruTexture);
	subTexture.loadFromFile("submarine.png");
	Submarine.setTexture(&subTexture);
	desTexture.loadFromFile("destroyer.png");
	Destroyer.setTexture(&desTexture);
	
	//shot textures
	targetShotTexture.loadFromFile("crosshairs.png");
	targetShot.setTexture(&targetShotTexture);
	hitShipTexture.loadFromFile("hitTarget.png");
	hitShip.setTexture(&hitShipTexture);
	missShipTexture.loadFromFile("missTarget.png");
	missShip.setTexture(&missShipTexture);

	//Set ship status and brings background, ships need shot types for callbackground function
	callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShip, missShip);
	Carrier.setStatus(placeCarrier(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Battleship.setStatus(placeBattleship(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Cruiser.setStatus(placeCruiser(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Submarine.setStatus(placeSubmarine(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Destroyer.setStatus(placeDestroyer(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	targetShot.setShotStatus(placeShot(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	
	//example shot, needs opponents ships as inputs instead of own ships
	targetShot.setShotStatus(placeShot(targetShot, hitShip, missShip, Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));

	//Text to spawn opponent ships
	callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background);
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text title;
	title.setFont(font);
	title.setString("Spawning opponents ships. . .");
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(40);
	title.setPosition(360, 620);
	window.draw(title);
	window.display();

	//Opponent ship vector with all ships
	Ship opponentShips[5] =
	{
		Ship(sf::Vector2f(30, 230), sf::Vector2f(660, 110)),
		Ship(sf::Vector2f(30, 180), sf::Vector2f(660, 110)),
		Ship(sf::Vector2f(30, 130), sf::Vector2f(660, 110)),
		Ship(sf::Vector2f(30, 130), sf::Vector2f(660, 110)),
		Ship(sf::Vector2f(30, 80), sf::Vector2f(660, 110))
	};
	for (int i = 0; i < 5; i++)
		opponentShips[i].setFillColor(sf::Color::Black);	//Make ships black

	spawnOpponentShips(opponentShips);				//Spawn in opponent ships and place them randomly on the board


	while (window.isOpen())
	{
		//game
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShip, missShip);
		for (int i = 0; i < 5; i++)
			window.draw(opponentShips[i]);
		window.display();
	}
}
