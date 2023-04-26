#include "header.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Battleship");
	Ship Carrier(sf::Vector2f(30, 230), sf::Vector2f(60, 110), sf::Color(0, 0, 0)), Battleship(sf::Vector2f(30, 180), sf::Vector2f(60, 110), sf::Color(50,50,50)), Cruiser(sf::Vector2f(30, 130), sf::Vector2f(60, 110), sf::Color(100, 100, 100)), Submarine(sf::Vector2f(30, 130), sf::Vector2f(60, 110), sf::Color(150, 150, 150)), Destroyer(sf::Vector2f(30, 80), sf::Vector2f(60, 110), sf::Color(200, 200, 200));
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer);
	Carrier.setStatus(placeCarrier(Carrier, Battleship, Cruiser, Submarine, Destroyer, window));
	Battleship.setStatus(placeBattleship(Carrier, Battleship, Cruiser, Submarine, Destroyer, window));
	Cruiser.setStatus(placeCruiser(Carrier, Battleship, Cruiser, Submarine, Destroyer, window));
	Submarine.setStatus(placeSubmarine(Carrier, Battleship, Cruiser, Submarine, Destroyer, window));
	Destroyer.setStatus(placeDestroyer(Carrier, Battleship, Cruiser, Submarine, Destroyer, window));

	//add opponents ship generation
	while (window.isOpen())
	{
		//game



		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer);
		window.display();
	}
}