#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
#include "Board.h"
#include "Textures.h"
void update(Board&, sf::RenderWindow &window, sf::Sprite newSprite, sf::Sprite iconSprite, sf::Texture texture, sf::Texture iconTexture, Textures &tex);
void showTile(int i, int j, Board&, sf::RenderWindow &window, sf::Sprite newSprite, sf::Sprite iconSprite, sf::Texture texture, sf::Texture iconTexture, Textures &tex);
class Update
{
public:

	//Update();
	//~Update();
};

