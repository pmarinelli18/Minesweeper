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

				if (i != 0)
				{
					if (j != 0)
					{
						if (!(*gameBoard.getTile(i - 1, j - 1)).getIsShown())
						{
							(*gameBoard.getTile(i - 1, j - 1)).setIsShown(1);
							showTile(i - 1, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}
					}
					if (j != 15)
					{
						if (!(*gameBoard.getTile(i - 1, j + 1)).getIsShown())
						{
							(*gameBoard.getTile(i - 1, j + 1)).setIsShown(1);
							showTile(i - 1, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}
					}
					if (!(*gameBoard.getTile(i - 1, j)).getIsShown())
					{
						(*gameBoard.getTile(i - 1, j)).setIsShown(1);
						showTile(i - 1, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture,tex);
					}
				}
				if (i != 24)
				{
					if (j != 0)
					{
						if (!(*gameBoard.getTile(i + 1, j - 1)).getIsShown())
						{
							(*gameBoard.getTile(i + 1, j - 1)).setIsShown(1);
							showTile(i + 1, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}
						if (j != 15)
						{
							if (!(*gameBoard.getTile(i + 1, j + 1)).getIsShown())
							{
								(*gameBoard.getTile(i + 1, j + 1)).setIsShown(1);
								showTile(i + 1, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);

							}
						}
						if (!(*gameBoard.getTile(i + 1, j)).getIsShown())
						{
							(*gameBoard.getTile(i + 1, j)).setIsShown(1);
							showTile(i + 1, j, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
						}

					}
				}
						if (j != 0)
						{
							if (!(*gameBoard.getTile(i, j - 1)).getIsShown())
							{
								(*gameBoard.getTile(i, j - 1)).setIsShown(1);
								showTile(i, j - 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
							}
						}
						if (j != 15)
						{
							if (!(*gameBoard.getTile(i, j + 1)).getIsShown())
							{
								(*gameBoard.getTile(i, j + 1)).setIsShown(1);
								showTile(i, j + 1, gameBoard, window, newSprite, iconSprite, texture, iconTexture, tex);
							}
						}
					
				
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

			/*Update::Update()
		{
		}


		Update::~Update()
		{
		}*/