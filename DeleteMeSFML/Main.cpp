#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "Tank.h"
#include "Input.h"
#include "GameState.h"
#include "SFML/Audio.hpp"
#include "Aural.h"
#include <list>
#include "Bullet.h"

//Destructor - how to kill a tank in an array
//Game State - Title screen, Main Game, Game Over Screen
//Bullets

//Ammunition - different types, different states
//Cannons - different types including machine guns, different turn speeds, hit points, different shot velocities
//Bodies - different armour - different speeds and sizes, can take multiple cannons




int main()
{
	srand(time(0));

	//Window
	sf::VideoMode Res = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(Res.width, Res.height), "LearningTanks", sf::Style::None | sf::Style::Fullscreen);
	//window.setPosition(sf::Vector2i(Res.width * 0.1, Res.height * 0.1));
	window.setMouseCursorVisible(false);

	//Music
	Aural gameSong;
	sf::Music* gmusic = new sf::Music;
	


	


	


//use function here



	// Collision Test Circle
	sf::CircleShape newShape;
	newShape.setRadius(100.f);
	newShape.setPosition(300, 300);
	newShape.setFillColor(sf::Color::Blue);
	sf::FloatRect boundingBox = newShape.getGlobalBounds();

	sf::RectangleShape rectangle(sf::Vector2f(boundingBox.width, boundingBox.height));
	rectangle.setPosition(newShape.getPosition().x, newShape.getPosition().y);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::Green);
	rectangle.setOutlineThickness(3.0f);
	//End Collision Test Circle
	


	//Creating and loading texture
	sf::Texture background;
	if (!background.loadFromFile("background.jpg"))
	{
		printf("no texture");
	} 
	
	sf::Texture texture;
	if (!texture.loadFromFile("ptank.png"))
	{
		printf("no texture");
	}

	sf::Texture textureEnemy;
	if (!textureEnemy.loadFromFile("Carrier.png"))
	{
		printf("no texture");
	}


	sf::Texture gTitle;
	if (!gTitle.loadFromFile("onefineday.jpg"))
	{
		printf("no texture");
	}


	sf::Texture gTitleText;
	if (!gTitleText.loadFromFile("OSDTitle.png"))
	{
		printf("no texture");
	}

	sf::Texture gTitleText2;
	if (!gTitleText2.loadFromFile("OSDTitle2.png"))
	{
		printf("no texture");
	}

	sf::Texture tyrianBrown;
	if (!tyrianBrown.loadFromFile("tyrian_simplebrown.png"))
	{
		printf("no texture");
	}

	sf::Sprite sprTyrianBrown(tyrianBrown);
	sprTyrianBrown.setRotation(0.0f);
	sprTyrianBrown.setOrigin(9, 12.5);

	sf::Sprite sprTitleText(gTitleText);
	//sprTitleText.setScale(2.0f, 2.0f);
	sf::Sprite sprTitleText2(gTitleText2);
	//sprTitleText2.setScale(2.0f, 2.0f);
	//sprTitleText.setPosition(960, 720);

	//Creating Sprite
	sf::Sprite backSprite(background);
	sf::Sprite titleSprite(gTitle);


	//The Player Tank
	sf::Sprite* sprite = new sf::Sprite(texture);
	sprite->setPosition(30, 30);
	sprite->setOrigin(25.0f, 25.0f);
	Tank playerTank;
	playerTank.SetSprite(sprite);

	Input input;
	input.AttachTank(&playerTank);
	playerTank.Init();
	//End Player Tank


	//The Test Ship
	sprTyrianBrown.setPosition(50, 50);



	//End Test Ship



	//Bullet
	sf::Texture bulletTexture;
	bulletTexture.loadFromFile("bullet.png");
	sf::Sprite* sprBullet = new sf::Sprite(bulletTexture);
	//Bullet pbullet;
	//pbullet.SetSprite(sprBullet);
	//pbullet.Init();
	
	
	//playerTank.EquipBullet(&pbullet);

	
	//List Test
	std::list<Bullet*> listbullet;
	//why isn't it this? sf::Sprite* sprite = new sf::Sprite(texture);

	playerTank.EquipBulletList(listbullet, playerTank.GetPosition(), sprBullet);

	//End List Test


	//End Bullet
	
	

	//Enemies
	const int circlecount = 50;
	Tank tanks[circlecount];
	sf::RectangleShape eTankColSquare[circlecount];

	for (int i = 0; i < circlecount; i++)
	{
		//Create Sprite for enemy tanks set them
		sf::Sprite* newSprite = new sf::Sprite(textureEnemy);
		
		newSprite->setPosition(30, 30);
		newSprite->setOrigin(25.0f, 25.0f);

		//Limits placing them to the window size
		int randomX = rand() % window.getSize().x;
		int randomY = rand() % window.getSize().y;

		//Set sprite on tanks and place them randomly in the window
		tanks[i].SetSprite(newSprite);
		tanks[i].SetPosition(sf::Vector2f(randomX, randomY));
		tanks[i].Init();
		tanks[i].SetECol();
	}

	//std::list<sf::Sprite> sprites(tanks, tanks + sizeof(tanks) / sizeof(sf::Sprite));
	Bullet bullet;
	std::list<Bullet> bulletList(5, bullet);


	//End Enemies


	//Delta Time (Clock)
	sf::Clock deltaClock;
	
	//Test
	sf::Clock spinClock;
	float spin = 0;
	//End Test



	//
	//MAIN LOOP
	//

	//Title, Main, Game Over

	enum GameStates { Title, MainGame, Paused, GameOver };

	GameStates StateMachine;
	StateMachine = Title;

	//title to start to fade in after 3 seconds
	//over a period of 2 seconds

	//get elapsed time is == 3
	//start loop
	//a = 0, ramp up to 255
	sf::Clock clock;
	sf::Clock clock2;
	int a = 0;
	int b = 0;
	bool titlefadein = false;
	bool titlefadein2 = false;
	bool fadetitleup = true;

	sf::Vector2f convertTankPosition;
	

	while (window.isOpen())
	{
		
		gameSong.SetMusicTitle(gmusic);
		
		while (StateMachine == Title)
		{
			window.clear();

			if (clock.getElapsedTime().asSeconds() >= 3.0f)
			{
				titlefadein = true;
			}

			if (titlefadein == true && clock.getElapsedTime().asSeconds() > 0.1f)
			{
				if (a < 255)
				{
					a += 5;
				}
				clock.restart();
			}


			if (clock2.getElapsedTime().asSeconds() >= 8.0f)
			{
				titlefadein2 = true;
			}

			if (titlefadein2 == true && clock2.getElapsedTime().asSeconds() > 0.1f)
			{
				//if (b < 255)
				//{
				//	b += 15;
				//}
				//
				//if (b == 255)
				//{
				//	b = 0;
				//}


				if (b == 150)
				{
					fadetitleup = true;
				}
				
				if (b == 255)
				{
					fadetitleup = false;
				}

				if (fadetitleup == true)
				{
						b += 5;
				}
				
				if (fadetitleup == false)
				{
						b -= 5;
				}
				
				clock2.restart();
			}

			sprTitleText.setColor(sf::Color(255, 255, 255, a));
			sprTitleText2.setColor(sf::Color(255, 255, 255, b));
			
			window.draw(titleSprite);
			window.draw(sprTitleText);
			window.draw(sprTitleText2);
			window.display();
			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
			{
				StateMachine = MainGame;
				gameSong.SetMusicMain(gmusic);
			}
		}


		while (StateMachine == MainGame)
		{

			float dt = deltaClock.restart().asSeconds();
			//Delta time decouples from frame rate

			if (dt > 1.0f / 60.0f)
				//If the next frame is higher than 1 in 60 - the cap stops it from going further e,g window is held
			{
				dt = 1.0f / 60.0f;
			}



			//Clear Screen
			window.clear();
			input.Update(dt);

			//Iterate through enemies and move them randomly
			for (int i = 0; i < circlecount; i++)
			{
				sf::Vector2f movelose((rand() % 5) - 2, (rand() % 5) - 2);
				sf::Vector2f currentposition(tanks[i].GetPosition());
			
				tanks[i].SetPosition((movelose * dt * tanks[i].GetTankSpeed()) + currentposition);
			}


			// UPDATES
			for (int i = 0; i < circlecount; ++i)
			{
				tanks[i].Update(dt);
			}
			playerTank.Update(dt);
			convertTankPosition = playerTank.GetPosition();
			//pbullet.Update(dt, convertTankPosition, playerTank.GetDirection());
			
			std::list<Bullet*>::iterator biter = listbullet.begin();

			for (biter; biter != listbullet.end(); ++biter)
			{
				(*biter)->Update(dt, playerTank.GetPosition(), playerTank.GetDirection());
			}

			if(spinClock.getElapsedTime().asSeconds() > 0.1f)
			{
				spin = spin + 1;
				sprTyrianBrown.setRotation(spin);
				spinClock.restart().asSeconds();
			}
			
			
			//END UPDATE


			//DRAW
			window.draw(backSprite);
			window.draw(newShape);
			window.draw(rectangle);


			for (int i = 0; i < circlecount; i++)
			{
				if (tanks[i].GetDrawable() != NULL)
				{
					tanks[i].Draw(&window);
				}
			}

			
			//Temp Fire Test
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
			{
				playerTank.FireCannon();
				//pbullet.SetPosition(sf::Vector2f(50, 50));
			}

			for (biter; biter != listbullet.end(); ++biter)
			{
				(*biter)->Draw(&window);
				
				//if ((*biter)->INFLIGHT)
				//{
				//	(*biter)->Draw(&window);
				//}
			}


			//End Fire Test




			playerTank.Draw(&window);
			//pbullet.Draw(&window);
			//How to only draw the current bullet...

			window.draw(sprTyrianBrown);

			//END DRAW


			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				StateMachine = Title;
			}

			window.display();

		}


		//EndMainLoop
	}


	return 0;
}
