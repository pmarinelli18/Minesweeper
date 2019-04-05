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
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	
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
	digit2.setTexture(tex.textures["digits"]);
	digit2.setPosition(0, 32 * 16);
	digit3.setTexture(tex.textures["digits"]);
	digit3.setPosition(0, 32 * 16);


	int mouseX = 0;
	int mouseY = 0;
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mouseX = event.mouseButton.x / 32;
				mouseY = event.mouseButton.y / 32;
				std::cout << (*gameBoard.getTile(mouseX, mouseY)).getNearByMines();
				std::cout << "leftMouse x, y : " << mouseX << ", " << mouseY << std::endl;
				if (mouseY < 16)
				{
					if (gameBoard.getGameState() == 0)
					{
						if ((*gameBoard.getTile(mouseX, mouseY)).getIsMine())
						{
							face.setTexture(tex.textures["faceLose"]);
							gameBoard.lostGame();
							gameBoard.showBombs();
						}
						(*gameBoard.getTile(mouseX, mouseY)).setIsShown(1);

					}
				}
				else if ( mouseX > (10) && mouseX < (13))
				{
					face.setTexture(tex.textures["faceHappy"]);
					std::cout<< "yup";
					(gameBoard.resetBoard());
				}
				else if (mouseX > 15 && mouseX < 18)
				{
					gameBoard.showBombs();
				}
				else if (mouseX > 17 && mouseX < 20)
				{
					gameBoard.loadGame("boards/test1.brd");
				}
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "RightMouse x, y : " << event.mouseButton.x / 32 << ", " << event.mouseButton.y / 32 << std::endl;
				(*gameBoard.getTile(event.mouseButton.x / 32, event.mouseButton.y / 32)).setIsFlag(!(*gameBoard.getTile(event.mouseButton.x / 32, event.mouseButton.y / 32)).getIsFlag());
			}
		}
		window.clear();
		update(gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
		window.draw(test1);
		window.draw(test2);
		window.draw(test3);
		window.draw(debug);
		window.draw(face);
		window.draw(digit1);
		window.draw(digit2);
		window.draw(digit3);
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