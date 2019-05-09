#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Board.h"
#include "Tiles.h"
#include "Update.h"
#include <map>
#include "Textures.h"
//sf::Texture loadSprite(std::string filename);

int main()
{
	Textures tex = Textures();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper!");
	
	//sf::CircleShape shape(100.f);

	//shape.setFillColor(sf::Color::Green);
	Board gameBoard;
	//window.display();
	//std::cout << (*gameBoard.getTile(0, 0)).getIsShown();
	//(*gameBoard.getTile(0, 0)).setIsShown(1);
	sf::Sprite newSprite;
	sf::Texture texture;
	sf::Sprite iconSprite;
	sf::Texture iconTexture;

	sf::Sprite test1;
	sf::Sprite test2;
	sf::Sprite test3;
	sf::Sprite debug;
	sf::Sprite face;
	sf::Sprite digit1;
	sf::Sprite digit2;
	sf::Sprite digit3;
	test1.setTexture(tex.textures["test1"]);
	test1.setPosition(574, 32 * 16);

	test2.setPosition(638, 32*16);
	test2.setTexture(tex.textures["test2"]);
	test3.setTexture(tex.textures["test3"]);
	test3.setPosition(702, 32*16);
	debug.setTexture(tex.textures["debug"]);
	debug.setPosition(510, 32 * 16);
	face.setTexture(tex.textures["faceHappy"]);
	face.setPosition(350, 32 * 16);
	digit1.setTexture(tex.textures["digits"]);
	digit1.setPosition(0, 32 * 16);
	digit1.setTextureRect(sf::IntRect(0, 0, 21, 32));
	digit2.setTexture(tex.textures["digits"]);
	digit2.setPosition(21, 32 * 16);
	digit2.setTextureRect(sf::IntRect(105, 0, 21, 32));
	digit3.setTexture(tex.textures["digits"]);
	digit3.setPosition(42, 32 * 16);
	digit3.setTextureRect(sf::IntRect(0, 0, 21, 32));


	int mouseX = 0;
	int mouseY = 0;
	bool flag = false;
	bool mouseReleased = false;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";// "WELCOME TO BRET SWEEPWER\nBRET IS A BOMB\nFOX IS THE FLAG\nKAYTON IS THE SMILEY FACE\nRED IS A LOSS\nAND GREEN IS A WIN\nHAVE FUN PLAYING!!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed && !mouseReleased)
		{
			mouseReleased = true;
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mouseX = event.mouseButton.x / 32;
				mouseY = event.mouseButton.y / 32;
				//std::cout << (*gameBoard.getTile(mouseX, mouseY)).getNearByMines();
				std::cout << "leftMouse x, y : " << mouseX << ", " << mouseY << std::endl;
				if (mouseY < 16)
				{
					if (gameBoard.getGameState() == 0 && !gameBoard.getTile(mouseX,mouseY)->getIsFlag())
					{
						if ((*gameBoard.getTile(mouseX, mouseY)).getIsMine())
						{
							face.setTexture(tex.textures["faceLose"]);
							gameBoard.lostGame();
							gameBoard.showBombs();
						}
						(*gameBoard.getTile(mouseX, mouseY)).setIsShown(1);
						//if ((gameBoard.getFlags()) == (gameBoard.getNumBombs()))
						{
							if(gameBoard.checkWin())
							{
								face.setTexture(tex.textures["faceWin"]);
								gameBoard.wonGame();
							}
						}
					}
						
				}
				else if ( mouseX > (10) && mouseX < (13))
				{
					face.setTexture(tex.textures["faceHappy"]);
					//std::cout<< "yup";
					(gameBoard.resetBoard());
					updateNumbers(gameBoard, window, digit1, digit2, digit3);
					
				}
				else if (mouseX > 15 && mouseX < 18)
				{
					gameBoard.showBombs();
					//gameBoard.
				}
				else if (mouseX > 17 && mouseX < 20)
				{
					face.setTexture(tex.textures["faceHappy"]);
					gameBoard.loadGame("boards/testboard1.brd");
				}
				else if (mouseX > 19 && mouseX < 22)
				{
					face.setTexture(tex.textures["faceHappy"]);
					gameBoard.loadGame("boards/testboard2.brd");
				}
				else if (mouseX > 21 && mouseX < 24)
				{
					face.setTexture(tex.textures["faceHappy"]);
					gameBoard.loadGame("boards/testboard3.brd");
				}
			}

			
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				mouseY = event.mouseButton.y / 32;
				if (gameBoard.getGameState() == 0 && mouseY < 16)
				{
					std::cout << "RightMouse x, y : " << event.mouseButton.x / 32 << ", " << event.mouseButton.y / 32 << std::endl;
					flag = (*gameBoard.getTile(event.mouseButton.x / 32, event.mouseButton.y / 32)).getIsFlag();
					(*gameBoard.getTile(event.mouseButton.x / 32, event.mouseButton.y / 32)).setIsFlag(!flag);
					if (!flag)
					{
						gameBoard.addFlag();
						//std::cout << gameBoard.getFlags();
					}
					else
					{
						gameBoard.subFlag();
						std::cout << "Num of bombs left:: " << 50 - gameBoard.getFlags() << std::endl;
					}
					//if ((gameBoard.getFlags()) + gameBoard. == (gameBoard.getNumBombs()))
					//{
						if (gameBoard.checkWin())
						{
							face.setTexture(tex.textures["faceWin"]);
							gameBoard.wonGame();
						}
					//}
				}
				//updateNumbers(gameBoard, window, digit1, digit2, digit3);

				/*int numLeft = 50 - gameBoard.getFlags();
				if (numLeft < 0)
				{
					digit1.setTextureRect(sf::IntRect(210, 0, 21, 32));
				}
				else
				{
					digit1.setTextureRect(sf::IntRect(0, 0, 21, 32));
				}
				switch (numLeft / 10)
				{
				case 0:
					digit2.setTextureRect(sf::IntRect(0, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits0"]);
					//window.draw(digit2);
					break;
				case 1:
					digit2.setTextureRect(sf::IntRect(21, 0, 21, 32));

					//digit2.setTexture(tex.textures["digits1"]);
					//window.draw(digit2);
					break;
				case 2:
					digit2.setTextureRect(sf::IntRect(42, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits2"]);
					//window.draw(digit2);
					break;
				case 3:
					digit2.setTextureRect(sf::IntRect(63, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits3"]);
					//window.draw(digit2);
					break;
				case 4:
					digit2.setTextureRect(sf::IntRect(84, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits4"]);
					//window.draw(digit2);
					break;
				case 5:
					digit2.setTextureRect(sf::IntRect(105, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits5"]);
					//window.draw(digit2);
					break;
				case 6:
					digit2.setTextureRect(sf::IntRect(126, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits6"]);
					//window.draw(digit2);
					break;
				case 7:
					digit2.setTextureRect(sf::IntRect(147, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits7"]);
					//window.draw(digit2);
					break;
				case 8:
					digit2.setTextureRect(sf::IntRect(168, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits8"]);
					//window.draw(digit2);
					break;
				case 9:
					digit2.setTextureRect(sf::IntRect(189, 0, 21, 32));
					//digit2.setTexture(tex.textures["digits9"]);
					//window.draw(digit2);
					break;
				}
				switch (numLeft % 10)
				{
				case 0:

					digit3.setTextureRect(sf::IntRect(0, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits0"]);
					//window.draw(digit3);
					break;
				case 1:
					digit3.setTextureRect(sf::IntRect(21, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits1"]);
					//window.draw(digit3);
					break;
				case 2:
					digit3.setTextureRect(sf::IntRect(42, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits2"]);
					//window.draw(digit3);
					break;
				case 3:
					digit3.setTextureRect(sf::IntRect(63, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits3"]);
					//window.draw(digit3);
					break;
				case 4:
					digit3.setTextureRect(sf::IntRect(84, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits4"]);
					//window.draw(digit3);
					break;
				case 5:
					digit3.setTextureRect(sf::IntRect(105, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits5"]);
					//window.draw(digit3);
					break;
				case 6:
					digit3.setTextureRect(sf::IntRect(126, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits6"]);
					//window.draw(digit3);
					break;
				case 7:
					digit3.setTextureRect(sf::IntRect(147, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits7"]);
					//window.draw(digit3);
					break;
				case 8:
					digit3.setTextureRect(sf::IntRect(168, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits8"]);
					//window.draw(digit3);
					break;
				case 9:
					digit3.setTextureRect(sf::IntRect(189, 0, 21, 32));
					//digit3.setTexture(tex.textures["digits9"]);
					//window.draw(digit3);
					break;
				}*/
			}
			//update(gameBoard, window, digit1, digit2, digit3, iconTexture, tex);
			
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			mouseReleased = false;
		}
		if (gameBoard.checkWin())
		{
			face.setTexture(tex.textures["faceWin"]);
			gameBoard.wonGame();
		}
		window.clear();
		update(gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
		updateNumbers(gameBoard, window, digit1, digit2, digit3);
		window.draw(test1);
		window.draw(test2);
		window.draw(test3);
		window.draw(debug);
		window.draw(face);
		//digit1.setTexture(tex.textures["digits"]);
		//digit2.setTexture(tex.textures["digits"]);
		//digit3.setTexture(tex.textures["digits"]);
		//window.draw(digit1);
		//window.draw(digit2);
		//window.draw(digit3);
		//window.drawBoard(newSprite);
		window.display();
	}
	system("pause");
	return 0;
}



/*
sf::Texture loadSprite(std::string filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);
	return texture;
}*/