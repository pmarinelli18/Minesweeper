#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
//#include <getline>
#include "tiles.h"
class Board
{
	class Tile array2D[25][16];
	bool showingBomb = 0;
	int gameState = 0;
	int flags = 0;
	int numBombs = 50;
public:
	void resetBoard();
	Tile* getTile(int column, int row);
	void showBombs();
	void lostGame() { gameState = 1; }
	void wonGame() { gameState = 2; }
	int getGameState() { return gameState; }
	int getNumBombs() { return numBombs; }
	void loadGame(std::string);
	int getFlags() { return flags; }
	void addFlag() { flags++; }
	void subFlag() { flags--; }
	bool checkWin();
	Board();
	~Board();
};

