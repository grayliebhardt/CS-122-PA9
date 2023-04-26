#include "header.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Battleship");
	Ship Carrier(sf::Vector2f(30, 230), sf::Vector2f(60, 110)), Battleship(sf::Vector2f(30, 180), sf::Vector2f(60, 110)), Cruiser(sf::Vector2f(30, 130), sf::Vector2f(60, 110)), Submarine(sf::Vector2f(30, 130), sf::Vector2f(60, 110)), Destroyer(sf::Vector2f(30, 80), sf::Vector2f(60, 110));
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

	callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background);
	Carrier.setStatus(placeCarrier(Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Battleship.setStatus(placeBattleship(Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Cruiser.setStatus(placeCruiser(Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Submarine.setStatus(placeSubmarine(Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));
	Destroyer.setStatus(placeDestroyer(Carrier, Battleship, Cruiser, Submarine, Destroyer, window, background));

	//add opponents ship generation
	while (window.isOpen())
	{
		//game
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background);
		window.display();
	}
}