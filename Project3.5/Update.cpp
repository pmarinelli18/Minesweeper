#include "Update.h"
void update(Board& gameBoard, sf::RenderWindow &window, sf::Sprite newSprite, sf::Sprite iconSprite, sf::Texture texture, sf::Texture iconTexture, Textures &tex)
{
	
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			/*
			sf::Sprite newSprite;
			newSprite.setPosition(sf::Vector2f((float)i * 32, (float)j * 32));
			sf::Texture texture;
			if (gameBoard.getTile(i, j).getIsShown())
			{
				texture.loadFromFile("images/tile_hidden.png");
			}
			else if (!gameBoard.getTile(i, j).getIsShown())
			{
				texture.loadFromFile("images/tile_revealed.png");
			}*/
			showTile(i, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
			//newSprite.setTexture(texture);

		}
	}
}
void showTile(int i, int j, Board &gameBoard, sf::RenderWindow &window, sf::Sprite newSprite, sf::Sprite iconSprite, sf::Texture texture, sf::Texture iconTexture , Textures &tex)
{
	newSprite = (*gameBoard.getTile(i, j)).getSprite();
	iconSprite = (*gameBoard.getTile(i, j)).getIcon();
	if ((*gameBoard.getTile(i, j)).getIsShown())
	{
		//std::cout << i << ", " << j << std::endl;  /////***************************************************************8
 		newSprite.setTexture((tex).textures["tileRevealed"]);
		//texture.loadFromFile("images/tile_revealed.png");
		if ((*gameBoard.getTile(i, j)).getIsMine())
		{
			iconSprite.setTexture((tex).textures["mine"]);
			//gameBoard.showBombs();
			//iconTexture.loadFromFile("images/mine.png");
		}
		else
		{
			switch (1 + (*gameBoard.getTile(i, j)).getNearByMines())
			{
			case 1:
				blankTile(i, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				break;
			case 2:
				iconSprite.setTexture((tex).textures["number1"]);
				//iconTexture.loadFromFile("images/number_1.png");
				break;
			case 3:
				iconSprite.setTexture((tex).textures["number2"]);
				//iconTexture.loadFromFile("images/number_2.png");
				break;
			case 4:
				iconSprite.setTexture((tex).textures["number3"]);
				//iconTexture.loadFromFile("images/number_3.png");
				break;
			case 5:
				iconSprite.setTexture((tex).textures["number4"]);
				//iconTexture.loadFromFile("images/number_4.png");
				break;
			case 6:
				iconSprite.setTexture((tex).textures["number5"]);
				//iconTexture.loadFromFile("images/number_5.png");
				break;
			case 7:
				iconSprite.setTexture((tex).textures["number6"]);
				//iconTexture.loadFromFile("images/number_6.png");
				break;
			case 8:
				iconSprite.setTexture((tex).textures["number7"]);
				//iconTexture.loadFromFile("images/number_7.png");
				break;
			case 9:
				iconSprite.setTexture((tex).textures["number8"]);
				//iconTexture.loadFromFile("images/number_8.png");
				break;
				//}
				}
			}
		}
				else
				{
					newSprite.setTexture((tex).textures["tileHidden"]);
					//texture.loadFromFile("images/tile_hidden.png");
					if ((*gameBoard.getTile(i, j)).getIsFlag())
					{
						iconSprite.setTexture((tex).textures["flag"]);
						//iconTexture.loadFromFile("images/flag.png");
					}
				}
				//newSprite = (*gameBoard.getTile(i, j)).getSprite();

				//newSprite.setTexture(texture);
				//iconSprite = (*gameBoard.getTile(i, j)).getIcon();
				//iconSprite.setTexture(iconTexture);
				
				try
				{
					window.draw(newSprite);
				}
				catch (int e)
				{
					std::cout <<"no enter NEWSPRITE";
				}
				//gameBoard.getTile(i, j).getSprite());
				try
				{
					window.draw(iconSprite);
				}
				catch (int e)
				{
					std::cout << "no enter ICON";

				}
			}
			void blankTile(int i, int j, Board &gameBoard, sf::RenderWindow &window, sf::Sprite newSprite, sf::Sprite iconSprite, sf::Texture texture, sf::Texture iconTexture, Textures &tex)
			{
				bool topLeft = false;
				bool topRight = false;
				bool topMid = false;
				bool midLeft = false;
				bool midRight = false;
				bool botLeft = false;
				bool botMid = false;
				bool botRight = false;
				
				if (i != 0)
				{
					if (j != 0)
					{
						if (!(*gameBoard.getTile(i - 1, j - 1)).getIsShown())
						{
							(*gameBoard.getTile(i - 1, j - 1)).setIsShown(1);
							topLeft = true;
							//showTile(i - 1, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}
					}
					if (j != 15)
					{
						if (!(*gameBoard.getTile(i - 1, j + 1)).getIsShown())
						{
							(*gameBoard.getTile(i - 1, j + 1)).setIsShown(1);
							botLeft = true;
							//showTile(i - 1, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}
					}
					if (!(*gameBoard.getTile(i - 1, j)).getIsShown())
					{
						(*gameBoard.getTile(i - 1, j)).setIsShown(1);
						midLeft = true;
						//showTile(i - 1, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
					}
				}
				if (i != 24)
				{
					if (j != 0)
					{
						if (!(*gameBoard.getTile(i + 1, j - 1)).getIsShown())
						{
							(*gameBoard.getTile(i + 1, j - 1)).setIsShown(1);
							topRight = true;
							//showTile(i + 1, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}
					}
					if (j != 15)
					{
						if (!(*gameBoard.getTile(i + 1, j + 1)).getIsShown())
						{
							(*gameBoard.getTile(i + 1, j + 1)).setIsShown(1);
							//showTile(i + 1, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
							botRight = true;
						}
					}

					if (!(*gameBoard.getTile(i + 1, j)).getIsShown())
					{
						(*gameBoard.getTile(i + 1, j)).setIsShown(1);
						midRight = true;
						//showTile(i + 1, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
					}
				}
				if (j != 0)
				{
					if (!(*gameBoard.getTile(i, j - 1)).getIsShown())
					{
						(*gameBoard.getTile(i, j - 1)).setIsShown(1);
						topMid = true;
						//showTile(i, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
					}
				}
				if (j != 15)
				{
					if (!(*gameBoard.getTile(i, j + 1)).getIsShown())
					{
						(*gameBoard.getTile(i, j + 1)).setIsShown(1);
						botMid = true;
						//showTile(i, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
					}
				}
				if (topLeft) showTile(i - 1, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(topMid)showTile(i, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(topRight) showTile(i + 1, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(midLeft) showTile(i - 1, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(midRight) showTile(i + 1, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(botLeft) showTile(i - 1, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(botMid) showTile(i, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
				if(botRight)showTile(i + 1, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
			}

			void updateNumbers(Board& gameBoard, sf::RenderWindow &window, sf::Sprite digit1, sf::Sprite digit2, sf::Sprite digit3)
			{
				int numLeft = gameBoard.getNumBombs() - gameBoard.getFlags();
				if (numLeft < 0)
				{
					digit1.setTextureRect(sf::IntRect(210, 0, 21, 32));
				}
				else
				{
					digit1.setTextureRect(sf::IntRect(0, 0, 21, 32));
				}
				switch (abs(numLeft / 10))
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
				switch (abs(numLeft % 10))
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
				}
				try
				{
					window.draw(digit1);
				}
				catch (int e)
				{
					std::cout << "no enter NEWSPRITE";
				}
				//gameBoard.getTile(i, j).getSprite());
				try
				{
					window.draw(digit2);
				}
				catch (int e)
				{
					std::cout << "no enter ICON";

				}
				try
				{
					window.draw(digit3);
				}
				catch (int e)
				{
					std::cout << "no enter ICON";

				}
			}
			/*Update::Update()
		{
		}


		Update::~Update()
		{
		}*/