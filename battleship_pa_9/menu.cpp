#include "header.hpp"
#include <random> // for random number generation

//Getter for if ship has loaded
bool Ship::getStatus()
{
	return loaded;
}

//Setter for ship load status
void Ship::setStatus(bool load)
{
	loaded = load;
}

//Render background and call it to game
void callbackground(sf::RenderWindow& window, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::Sprite background, Shot& targetShot, Shot& hitShot,)
{
	sf::Color backgroundcolor(110, 156, 230);
	sf::Text letter, number;
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	char lettercharacter, numbercharacter;
	window.clear(backgroundcolor);
	window.draw(background);
	for (int i = 0; i < 11; i++)
	{
		sf::Vertex horizontalline[] =
		{
			sf::Vertex(sf::Vector2f(650.f, 100.f + (50 * i))),
			sf::Vertex(sf::Vector2f(1150.f, 100.f + (50 * i)))
		};
		window.draw(horizontalline, 2, sf::Lines);
		sf::Vertex verticalline[] =
		{
			sf::Vertex(sf::Vector2f(650.f + (50 * i), 100.f)),
			sf::Vertex(sf::Vector2f(650.f + (50 * i), 600.f))
		};
		window.draw(verticalline, 2, sf::Lines);
	}
	for (int i = 0; i < 10; i++)
	{
		letter.setFont(font);
		number.setFont(font);
		lettercharacter = 65 + i;
		numbercharacter = 49 + i;
		if (numbercharacter == 58)
		{
			number.setString("10");
			number.setPosition(614.f, 105.f + (50 * i));
		}
		else
		{
			number.setString(numbercharacter);
			number.setPosition(623.f, 105.f + (50 * i));
		}
		letter.setString(lettercharacter);
		letter.setPosition(668.f + (50 * i), 60.f);
		letter.setFillColor(sf::Color::White);
		number.setFillColor(sf::Color::White);
		window.draw(letter);
		window.draw(number);
	}
	for (int i = 0; i < 11; i++)
	{
		sf::Vertex horizontalline[] =
		{
			sf::Vertex(sf::Vector2f(50.f, 100.f + (50 * i))),
			sf::Vertex(sf::Vector2f(550.f, 100.f + (50 * i)))
		};
		window.draw(horizontalline, 2, sf::Lines);
		sf::Vertex verticalline[] =
		{
			sf::Vertex(sf::Vector2f(50.f + (50 * i), 100.f)),
			sf::Vertex(sf::Vector2f(50.f + (50 * i), 600.f))
		};
		window.draw(verticalline, 2, sf::Lines);
	}
	for (int i = 0; i < 10; i++)
	{
		letter.setFont(font);
		number.setFont(font);
		lettercharacter = 65 + i;
		numbercharacter = 49 + i;
		if (numbercharacter == 58)
		{
			number.setString("10");
			number.setPosition(14.f, 105.f + (50 * i));
		}
		else
		{
			number.setString(numbercharacter);
			number.setPosition(23.f, 105.f + (50 * i));
		}
		letter.setString(lettercharacter);
		letter.setPosition(68.f + (50 * i), 60.f);
		letter.setFillColor(sf::Color::White);
		number.setFillColor(sf::Color::White);
		window.draw(letter);
		window.draw(number);
	}
	sf::Text title;
	title.setFont(font);
	title.setString("Your board");
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(40);
	title.setPosition(210, 10);
	window.draw(title);
	title.setString("Opponent's board");
	title.setPosition(760, 10);
	window.draw(title);

	if(Carrier.getStatus())
		window.draw(Carrier);
	if (Battleship.getStatus())
		window.draw(Battleship);
	if (Cruiser.getStatus())
		window.draw(Cruiser);
	if (Submarine.getStatus())
		window.draw(Submarine);
	if (Destroyer.getStatus())
		window.draw(Destroyer);
	if (targetShot.getShotStatus())
		window.draw(targetShot);
	if (hitShot.getShotStatus())
		window.draw(hitShot);
	if (missShot.getShotStatus())
		window.draw(missShot);

}

//Function for user to manually place ship, returns if successful or not
bool placeCarrier(Shot& targetShot, Shot& hitShot, Shot& missShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Use the arrow keys to position your Carrier, spacebar\nto rotate, and escape to confirm placement.");
	instructions.setPosition(50, 620);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (Carrier.getGlobalBounds().left + Carrier.getGlobalBounds().width + 50 < 550)
						Carrier.move(50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (Carrier.getGlobalBounds().top - 50 > 100)
						Carrier.move(0, -50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (Carrier.getGlobalBounds().left - 50 > 50)
						Carrier.move(-50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (Carrier.getGlobalBounds().top + Carrier.getGlobalBounds().height + 50 < 600)
						Carrier.move(0, 50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (Carrier.getGlobalBounds().height > Carrier.getGlobalBounds().width)
					{
						if (Carrier.getGlobalBounds().left + Carrier.getGlobalBounds().height < 550)
						{
							Carrier.setRotation(-90.f);
							Carrier.move(0, 30);
						}
						else
						{
							Carrier.setRotation(-90.f);
							Carrier.move(-200, 30);
						}
					}
					else
					{
						if (Carrier.getGlobalBounds().top + Carrier.getGlobalBounds().width < 600)
						{
							Carrier.setRotation(0.f);
							Carrier.move(0, -30);
						}
						else
						{
							Carrier.setRotation(0.f);
							Carrier.move(0, -230);
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
					window.draw(Carrier);
					window.draw(instructions);
					window.display();
					return true;
				}
			}
		}
		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
		window.draw(Carrier);
		window.draw(instructions);
		window.display();
		
	}
	return false;
}

//Function that is used to manually place battleship for user
bool placeBattleship(Shot& targetShot, Shot& hitShot, Shot& missShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Use the arrow keys to position your Battleship, spacebar\nto rotate, and escape to confirm placement.");
	instructions.setPosition(50, 620);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (Battleship.getGlobalBounds().left + Battleship.getGlobalBounds().width + 50 < 550)
						Battleship.move(50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (Battleship.getGlobalBounds().top - 50 > 100)
						Battleship.move(0, -50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (Battleship.getGlobalBounds().left - 50 > 50)
						Battleship.move(-50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (Battleship.getGlobalBounds().top + Battleship.getGlobalBounds().height + 50 < 600)
						Battleship.move(0, 50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (Battleship.getGlobalBounds().height > Battleship.getGlobalBounds().width)
					{
						if (Battleship.getGlobalBounds().left + Battleship.getGlobalBounds().height < 550)
						{
							Battleship.setRotation(-90.f);
							Battleship.move(0, 30);
						}
						else
						{
							Battleship.setRotation(-90.f);
							Battleship.move(-200, 30);
						}
					}
					else
					{
						if (Battleship.getGlobalBounds().top + Battleship.getGlobalBounds().width < 600)
						{
							Battleship.setRotation(0.f);
							Battleship.move(0, -30);
						}
						else
						{
							Battleship.setRotation(0.f);
							Battleship.move(0, -180);
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					if (Battleship.getGlobalBounds().intersects(Carrier.getGlobalBounds()))
					{
						instructions.setString("Use the arrow keys to position your Battleship, spacebar\nto rotate, and escape to confirm placement.\n\nShips cannot intersect, move your battleship.");
					}
					else {
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						window.draw(Battleship);
						window.draw(instructions);
						window.display();
						return true;
					}
				}
			}
		}
		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
		window.draw(Battleship);
		window.draw(instructions);
		window.display();

	}
	return false;
}

//Function manually places users cruiser
bool placeCruiser(Shot& targetShot, Shot& hitShot, Shot& missShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Use the arrow keys to position your Cruiser, spacebar\nto rotate, and escape to confirm placement.");
	instructions.setPosition(50, 620);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (Cruiser.getGlobalBounds().left + Cruiser.getGlobalBounds().width + 50 < 550)
						Cruiser.move(50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (Cruiser.getGlobalBounds().top - 50 > 100)
						Cruiser.move(0, -50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (Cruiser.getGlobalBounds().left - 50 > 50)
						Cruiser.move(-50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (Cruiser.getGlobalBounds().top + Cruiser.getGlobalBounds().height + 50 < 600)
						Cruiser.move(0, 50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (Cruiser.getGlobalBounds().height > Cruiser.getGlobalBounds().width)
					{
						if (Cruiser.getGlobalBounds().left + Cruiser.getGlobalBounds().height < 550)
						{
							Cruiser.setRotation(-90.f);
							Cruiser.move(0, 30);
						}
						else
						{
							Cruiser.setRotation(-90.f);
							Cruiser.move(-200, 30);
						}
					}
					else
					{
						if (Cruiser.getGlobalBounds().top + Cruiser.getGlobalBounds().width < 600)
						{
							Cruiser.setRotation(0.f);
							Cruiser.move(0, -30);
						}
						else
						{
							Cruiser.setRotation(0.f);
							Cruiser.move(0, -130);
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					if (Cruiser.getGlobalBounds().intersects(Carrier.getGlobalBounds()) || Cruiser.getGlobalBounds().intersects(Battleship.getGlobalBounds()))
					{
						instructions.setString("Use the arrow keys to position your Cruiser, spacebar\nto rotate, and escape to confirm placement.\n\nShips cannot intersect, move your Cruiser.");
					}
					else {
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						window.draw(Cruiser);
						window.draw(instructions);
						window.display();
						return true;
					}
				}
			}
		}
		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
		window.draw(Cruiser);
		window.draw(instructions);
		window.display();

	}
	return false;
}

//Function manually places users submarine
bool placeSubmarine(Shot& targetShot, Shot& hitShot, Shot& missShot,Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Use the arrow keys to position your Submarine, spacebar\nto rotate, and escape to confirm placement.");
	instructions.setPosition(50, 620);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (Submarine.getGlobalBounds().left + Submarine.getGlobalBounds().width + 50 < 550)
						Submarine.move(50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (Submarine.getGlobalBounds().top - 50 > 100)
						Submarine.move(0, -50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (Submarine.getGlobalBounds().left - 50 > 50)
						Submarine.move(-50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (Submarine.getGlobalBounds().top + Submarine.getGlobalBounds().height + 50 < 600)
						Submarine.move(0, 50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (Submarine.getGlobalBounds().height > Submarine.getGlobalBounds().width)
					{
						if (Submarine.getGlobalBounds().left + Submarine.getGlobalBounds().height < 550)
						{
							Submarine.setRotation(-90.f);
							Submarine.move(0, 30);
						}
						else
						{
							Submarine.setRotation(-90.f);
							Submarine.move(-200, 30);
						}
					}
					else
					{
						if (Submarine.getGlobalBounds().top + Submarine.getGlobalBounds().width < 600)
						{
							Submarine.setRotation(0.f);
							Submarine.move(0, -30);
						}
						else
						{
							Submarine.setRotation(0.f);
							Submarine.move(0, -130);
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					if (Submarine.getGlobalBounds().intersects(Carrier.getGlobalBounds()) || Submarine.getGlobalBounds().intersects(Battleship.getGlobalBounds()))
						instructions.setString("Use the arrow keys to position your Submarine, spacebar\nto rotate, and escape to confirm placement.\n\nShips cannot intersect, move your Submarine.");
					else if (Submarine.getGlobalBounds().intersects(Cruiser.getGlobalBounds()))
						instructions.setString("Use the arrow keys to position your Submarine, spacebar\nto rotate, and escape to confirm placement.\n\nShips cannot intersect, move your Submarine.");
					else {
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						window.draw(Submarine);
						window.draw(instructions);
						window.display();
						return true;
					}
				}
			}
		}
		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
		window.draw(Submarine);
		window.draw(instructions);
		window.display();

	}
	return false;
}

//Function manually places users destroyer
bool placeDestroyer(Shot& targetShot, Shot& hitShot, Shot& missShot,Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Use the arrow keys to position your Destroyer, spacebar\nto rotate, and escape to confirm placement.");
	instructions.setPosition(50, 620);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (Destroyer.getGlobalBounds().left + Destroyer.getGlobalBounds().width + 50 < 550)
						Destroyer.move(50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (Destroyer.getGlobalBounds().top - 50 > 100)
						Destroyer.move(0, -50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (Destroyer.getGlobalBounds().left - 50 > 50)
						Destroyer.move(-50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (Destroyer.getGlobalBounds().top + Destroyer.getGlobalBounds().height + 50 < 600)
						Destroyer.move(0, 50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (Destroyer.getGlobalBounds().height > Destroyer.getGlobalBounds().width)
					{
						if (Destroyer.getGlobalBounds().left + Destroyer.getGlobalBounds().height < 550)
						{
							Destroyer.setRotation(-90.f);
							Destroyer.move(0, 30);
						}
						else
						{
							Destroyer.setRotation(-90.f);
							Destroyer.move(-200, 30);
						}
					}
					else
					{
						if (Destroyer.getGlobalBounds().top + Destroyer.getGlobalBounds().width < 600)
						{
							Destroyer.setRotation(0.f);
							Destroyer.move(0, -30);
						}
						else
						{
							Destroyer.setRotation(0.f);
							Destroyer.move(0, -80);
						}
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					if (Destroyer.getGlobalBounds().intersects(Carrier.getGlobalBounds()) || Destroyer.getGlobalBounds().intersects(Battleship.getGlobalBounds()))
						instructions.setString("Use the arrow keys to position your Destroyer, spacebar\nto rotate, and escape to confirm placement.\n\nShips cannot intersect, move your Destroyer.");
					else if (Destroyer.getGlobalBounds().intersects(Cruiser.getGlobalBounds()) || Destroyer.getGlobalBounds().intersects(Submarine.getGlobalBounds()))
						instructions.setString("Use the arrow keys to position your Destroyer, spacebar\nto rotate, and escape to confirm placement.\n\nShips cannot intersect, move your Destroyer.");
					else {
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background);
						window.draw(Destroyer);
						window.draw(instructions);
						window.display();
						return true;
					}
				}
			}
		}
		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background);
		window.draw(Destroyer);
		window.draw(instructions);
		window.display();

	}
	return false;
}

//Spawns opponent ships randomly
void spawnOpponentShips(Ship opponentships[])
{
	
	for (int i = 0; i < 5; i++)
	{
		switch (i) {

		case 0:
			do
			{
				placeSingleOpponentShip(opponentships[i]);
			} while ((opponentships[i].getGlobalBounds().left + opponentships[i].getGlobalBounds().width > 1160) || (opponentships[i].getGlobalBounds().top + opponentships[i].getGlobalBounds().height > 600));
			break;
		case 1:
			do
			{
				placeSingleOpponentShip(opponentships[i]);
			} while ((opponentships[i].getGlobalBounds().intersects(opponentships[i - 1].getGlobalBounds())) || (opponentships[i].getGlobalBounds().left + opponentships[i].getGlobalBounds().width > 1160) || (opponentships[i].getGlobalBounds().top + opponentships[i].getGlobalBounds().height > 600));
			break; 
		case 2:
			do
			{
				placeSingleOpponentShip(opponentships[i]);
			} while ((opponentships[i].getGlobalBounds().intersects(opponentships[i - 1].getGlobalBounds())) || (opponentships[i].getGlobalBounds().intersects(opponentships[i - 2].getGlobalBounds())) || (opponentships[i].getGlobalBounds().left + opponentships[i].getGlobalBounds().width > 1160) || (opponentships[i].getGlobalBounds().top + opponentships[i].getGlobalBounds().height > 600));
			break;
		case 3:
			do
			{
				placeSingleOpponentShip(opponentships[i]);
			} while ((opponentships[i].getGlobalBounds().intersects(opponentships[i - 1].getGlobalBounds())) || (opponentships[i].getGlobalBounds().intersects(opponentships[i - 2].getGlobalBounds())) || (opponentships[i].getGlobalBounds().intersects(opponentships[i - 3].getGlobalBounds())) || (opponentships[i].getGlobalBounds().left + opponentships[i].getGlobalBounds().width > 1160) || (opponentships[i].getGlobalBounds().top + opponentships[i].getGlobalBounds().height > 600));
			break;
		case 4:
			do
			{
				placeSingleOpponentShip(opponentships[i]);
			} while ((opponentships[i].getGlobalBounds().intersects(opponentships[i-1].getGlobalBounds())) || (opponentships[i].getGlobalBounds().intersects(opponentships[i - 2].getGlobalBounds())) || (opponentships[i].getGlobalBounds().intersects(opponentships[i - 3].getGlobalBounds())) || (opponentships[i].getGlobalBounds().intersects(opponentships[i - 4].getGlobalBounds())) || (opponentships[i].getGlobalBounds().left + opponentships[i].getGlobalBounds().width > 1160) || (opponentships[i].getGlobalBounds().top + opponentships[i].getGlobalBounds().height > 600));

			break;
		
		}
	}
}

//Function used to place each ship
void placeSingleOpponentShip(Ship& ship)
{
	srand(time(NULL));
	int orientation, row, col;
	orientation = rand() % 2;
	row = rand() % 10;
	col = rand() % 10;
	ship.setRotation(0);
	ship.setPosition(660, 110);
	ship.move(50 * col, 50 * row);
	if (orientation == 1)
	{
		ship.setRotation(-90.f);
		ship.move(0, 30);
		
	}
}

bool placeShot(int& hits, Shot& targetShot, Shot& hitShot, Shot&missShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
	sf::Font font;
	font.loadFromFile("MachineStd.otf");
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Use the arrow keys to position your Shot, spacebar\nto confirm placement.");
	instructions.setPosition(100, 620);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (targetShot.getGlobalBounds().left + targetShot.getGlobalBounds().width + 50 < 550)
						targetShot.move(50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (targetShot.getGlobalBounds().top - 50 > 100)
						targetShot.move(0, -50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (targetShot.getGlobalBounds().left - 50 > 50)
						targetShot.move(-50, 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (targetShot.getGlobalBounds().top + targetShot.getGlobalBounds().height + 50 < 600)
						targetShot.move(0, 50);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (targetShot.getGlobalBounds().intersects(hitShot.getGlobalBounds()) || targetShot.getGlobalBounds().intersects(missShot.getGlobalBounds()))
					{
						instructions.setString("Already shot there, try somewhere else.");
					}

					else if (targetShot.getGlobalBounds().intersects(Carrier.getGlobalBounds()))
					{
						instructions.setString("Carrier hit!");
						hitShot.setPosition(targetShot.getPosition());
						hitShot.setShotStatus(true);
						window.draw(hitShot);
						targetShot.setShotStatus(false);
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						hits++;
						return true;
					}
					else if (targetShot.getGlobalBounds().intersects(Destroyer.getGlobalBounds()))
					{
						instructions.setString("Destroyer hit!");
						hitShot.setPosition(targetShot.getPosition());
						hitShot.setShotStatus(true);
						window.draw(hitShot);
						hits++;

						//not sure why its still drawing target shots permanently with this line of code
						targetShot.setShotStatus(false);
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						return true;
					}
					else if (targetShot.getGlobalBounds().intersects(Battleship.getGlobalBounds()))
					{
						instructions.setString("Battleship hit!");
						hitShot.setPosition(targetShot.getPosition());
						hitShot.setShotStatus(true);
						window.draw(hitShot);
						targetShot.setShotStatus(false);
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						hits++;
						return true;
					}
					else if (targetShot.getGlobalBounds().intersects(Cruiser.getGlobalBounds()))
					{
						instructions.setString("Cruiser hit!");
						hitShot.setPosition(targetShot.getPosition());
						hitShot.setShotStatus(true);
						window.draw(hitShot);
						targetShot.setShotStatus(false);
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
						hits++;
						return true;
					}
					else if (targetShot.getGlobalBounds().intersects(Submarine.getGlobalBounds()))
					{
						instructions.setString("Submarine hit!");
						hitShot.setPosition(targetShot.getPosition());
						hitShot.setShotStatus(true);
						window.draw(hitShot);
						targetShot.setShotStatus(false);
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot, targetShot, hitShot, missShot);
						hits++;
						return true;
					}
						
					else {
						instructions.setString("Miss!");
						missShot.setPosition(targetShot.getPosition());
						missShot.setShotStatus(true);
						window.draw(missShot);
						callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot, targetShot, hitShot, missShot);

						window.draw(instructions);
						window.display();
						return true;
					}
				}
			}
		}
		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot, targetShot, hitShot, missShot);
		window.draw(targetShot);
		window.draw(instructions);
		window.display();

	}
	return false;
}

bool placeComputerShot(int& hits, Shot& targetShot, Shot& hitShot, Shot& missShot, Ship& Carrier, Ship& Battleship, Ship& Cruiser, Ship& Submarine, Ship& Destroyer, sf::RenderWindow& window, sf::Sprite background)
{
    std::random_device rd; // obtain a random seed from the hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> xDist(50, 550); // define the range of x coordinates
    std::uniform_int_distribution<> yDist(100, 600); // define the range of y coordinates

    // generate a random position for the shot
    int x = xDist(eng);
    int y = yDist(eng);
    targetShot.setPosition(x, y);

    // check if the shot hits a ship
    if (targetShot.getGlobalBounds().intersects(Carrier.getGlobalBounds()))
    {
        hits++;
        instructions.setString("Carrier hit!");
        hitShot.setPosition(targetShot.getPosition());
        hitShot.setShotStatus(true);
        window.draw(hitShot);
        callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
        return true;
    }
    else if (targetShot.getGlobalBounds().intersects(Destroyer.getGlobalBounds()))
    {
        hits++;
        instructions.setString("Destroyer hit!");
        hitShot.setPosition(targetShot.getPosition());
        hitShot.setShotStatus(true);
        window.draw(hitShot);
        callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
        return true;
    }
    else if (targetShot.getGlobalBounds().intersects(Battleship.getGlobalBounds()))
    {
        hits++;
        instructions.setString("Battleship hit!");
        hitShot.setPosition(targetShot.getPosition());
        hitShot.setShotStatus(true);
        window.draw(hitShot);
        callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
        return true;
    }
    else if (targetShot.getGlobalBounds().intersects(Cruiser.getGlobalBounds()))
    {
        hits++;
        instructions.setString("Cruiser hit!");
        hitShot.setPosition(targetShot.getPosition());
        hitShot.setShotStatus(true);
        window.draw(hitShot);
        callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
        return true;
    }
    else if (targetShot.getGlobalBounds().intersects(Submarine.getGlobalBounds()))
    {
        hits++;
        instructions.setString("Submarine hit!");
        hitShot.setPosition(targetShot.getPosition());
        hitShot.setShotStatus(true);
        window.draw(hitShot);
        callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
        return true;
    }
    else
    {
        instructions.setString("Miss!");
        missShot.setPosition(targetShot.getPosition());
        missShot.setShotStatus(true);
        window.draw(missShot);
        callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShot, missShot);
        return true;
    }
}

