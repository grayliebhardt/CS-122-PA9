#include "header.hpp"

void gameWrapper(void)
{
	//Creates Main Menu Window 
	sf::RenderWindow MENU(sf::VideoMode(1200, 800), "Main Menu", sf::Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//Main Menu Background
	sf::RectangleShape MainBackground;
	MainBackground.setSize(sf::Vector2f(1200, 800));
	sf::Texture MainTexture;
	MainTexture.loadFromFile("battleship cover.jpg");
	MainBackground.setTexture(&MainTexture);

	//About Option Background w/ Rules  
	sf::RectangleShape AboutBackground;
	AboutBackground.setSize(sf::Vector2f(1200, 800));
	sf::Texture about_texture;
	about_texture.loadFromFile("battleship rules.jpg");
	AboutBackground.setTexture(&about_texture);

	//Main Menu Options 
	while (MENU.isOpen())
	{
		sf::Event menupick;
		while (MENU.pollEvent(menupick))
		{
			if (menupick.type == sf::Event::Closed)
			{
				MENU.close();
			}
			if (menupick.type == sf::Event::KeyReleased)
			{
				if (menupick.key.code == sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (menupick.key.code == sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (menupick.key.code == sf::Keyboard::Return)
				{
					sf::RenderWindow Play(sf::VideoMode(1200, 800), "Play");
					sf::RenderWindow ABOUT(sf::VideoMode(1200, 800), "ABOUT");
					sf::RenderWindow EXIT(sf::VideoMode(1200, 800), "EXIT");

					int x = mainMenu.MainMenuPressed();

					//if Play option is picked
					if (x == 0)
					{
						MENU.close();
						break;
					}

					//if About option is picked 
					if (x == 1)
					{
						while (ABOUT.isOpen())
						{
							sf::Event menupick;
							while (ABOUT.pollEvent(menupick))
							{
								if (menupick.type == sf::Event::Closed)
								{
									ABOUT.close();
								}
								if (menupick.type == sf::Event::KeyPressed)
								{
									if (menupick.key.code == sf::Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
							}
							Play.close();
							ABOUT.clear();
							ABOUT.draw(AboutBackground);
							EXIT.close();
							ABOUT.display();
						}
					}
					//if Exit option is picked 
					if (x == 2)
					{
						MENU.close();
						exit(0);
					}
				}
			}
		}
		MENU.clear();
		MENU.draw(MainBackground);
		mainMenu.draw(MENU);
		MENU.display();
	}
	
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
		int cpuHitCounter = 0;
		int userHitCounter = 0;
		
		//game
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || cpuHitCounter >= 17 || userHitCounter > = 17)
				window.close();
		}


		callbackground(window, Carrier, Battleship, Cruiser, Submarine, Destroyer, background, targetShot, hitShip, missShip);
		for (int i = 0; i < 5; i++)
			window.draw(opponentShips[i]);
		window.display();
	}
}
