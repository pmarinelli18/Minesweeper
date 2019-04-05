#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>
class Tile
{
	bool isFlag;
	bool isMine;
	bool isShown;
	int nearByMines;
	sf::Sprite tileSprite;
	sf::Sprite icon;
public:
	bool getIsShown() { return isShown; }
	bool getIsFlag() { return isFlag; }
	bool getIsMine() { return isMine; }
	int getNearByMines() { return nearByMines; };
	sf::Sprite getSprite() { return tileSprite; }
	sf::Sprite getIcon() { return icon; };
	void setIsShown(bool shown) { isShown = shown; }
	void setIsFlag(bool flag) { isFlag = flag; }
	void setIsMine(bool mine) { isMine = mine; }
	void setNearByMines(int numMines) { nearByMines = numMines; };
	//void setSprite(sf::Sprite sprite) { tileSprite = sprite; }
	Tile()
	{	
		nearByMines= 0;
		isFlag = false;
		isMine = false;
		isShown = false;
		sf::Texture texture;
		texture.loadFromFile("images/tile_hidden.png");
		tileSprite.setTexture(texture);
	}
	Tile(int i, int j)
	{
		nearByMines = 0;
		isFlag = false;
		isMine = false;
		isShown = false;
		tileSprite.setPosition(i * 32, j * 32);
		icon.setPosition(i * 32, j * 32);
	}
	~Tile() {}
};


