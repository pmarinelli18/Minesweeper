#include "Board.h"
/*void Board::resetBoard(int numBombs, class Tile array2D[])
{
	std::cout << "hi";
}*/

Board::Board()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			Tile newTile(i, j);
			//newTile.getSprite().setPosition(sf::Vector2f((float)i * 32, (float)j * 32));
			array2D[i][j] = newTile;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		bool flag = false;
		while (!flag)
		{
			int iValue = rand() % 25;
			int jValue = rand() % 16;
			if (!array2D[iValue][jValue].getIsMine())
			{
				array2D[iValue][jValue].setIsMine(true);
				flag = true;
			}
		}
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (array2D[i][j].getIsMine())
			{
				if (i != 0)
				{
					if (j != 0)
					{
						array2D[i - 1][j - 1].setNearByMines(array2D[i - 1][j - 1].getNearByMines() + 1);
					}
					if (j != 15)
					{
						array2D[i - 1][j + 1].setNearByMines((array2D[i - 1][j + 1].getNearByMines()) + 1);
					}
					array2D[i - 1][j].setNearByMines(array2D[i - 1][j].getNearByMines() + 1);
				}
				if (i != 24)
				{
					if (j != 0)
					{
						array2D[i + 1][j - 1].setNearByMines(array2D[i + 1][j - 1].getNearByMines() + 1);
					}
					if (j != 15)
					{
						array2D[i + 1][j + 1].setNearByMines(array2D[i + 1][j + 1].getNearByMines() + 1);
					}
					array2D[i + 1][j].setNearByMines(array2D[i + 1][j].getNearByMines() + 1);
				}
				if (j != 0)
				{
					array2D[i][j - 1].setNearByMines(array2D[i][j - 1].getNearByMines() + 1);
				}
				if (j != 15)
				{
					array2D[i][j + 1].setNearByMines(array2D[i][j + 1].getNearByMines() + 1);
				}
			}
		}
	}

}
Tile* Board::getTile(int column, int row)
{
	return &array2D[column][row];
}
void Board::resetBoard()
{
	std::cout << "Reseting Board!!\n";
	gameState = 0;
	showingBomb = 0;
	flags = 0;
	numBombs = 50;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			
			array2D[i][j].setIsShown(0);
			array2D[i][j].setIsFlag(0);
			array2D[i][j].setIsMine(0);
			array2D[i][j].setNearByMines(0);
		}
	}
	for (int i = 0; i < 50; i++)
	{
		bool flag = false;
		while (!flag)
		{
			int iValue = rand() % 25;
			int jValue = rand() % 16;
			if (!array2D[iValue][jValue].getIsMine())
			{
				array2D[iValue][jValue].setIsMine(true);
				flag = true;
			}
		}
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (array2D[i][j].getIsMine())
			{
				if (i != 0)
				{
					if (j != 0)
					{
						array2D[i - 1][j - 1].setNearByMines(array2D[i - 1][j - 1].getNearByMines() + 1);
					}
					if (j != 15)
					{
						array2D[i - 1][j + 1].setNearByMines((array2D[i - 1][j + 1].getNearByMines()) + 1);
					}
					array2D[i - 1][j].setNearByMines(array2D[i - 1][j].getNearByMines() + 1);
				}
				if (i != 24)
				{
					if (j != 0)
					{
						array2D[i + 1][j - 1].setNearByMines(array2D[i + 1][j - 1].getNearByMines() + 1);
					}
					if (j != 15)
					{
						array2D[i + 1][j + 1].setNearByMines(array2D[i + 1][j + 1].getNearByMines() + 1);
					}
					array2D[i + 1][j].setNearByMines(array2D[i + 1][j].getNearByMines() + 1);
				}
				if (j != 0)
				{
					array2D[i][j - 1].setNearByMines(array2D[i][j - 1].getNearByMines() + 1);
				}
				if (j != 15)
				{
					array2D[i][j + 1].setNearByMines(array2D[i][j + 1].getNearByMines() + 1);
				}
			}
		}
	}
}
void Board::showBombs()
{
	std::cout << "Toggling Bombs\n";
	showingBomb = !showingBomb;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (array2D[i][j].getIsMine())
			{
				array2D[i][j].setIsShown(showingBomb);
			}
		}
	}
}
void Board::loadGame(std::string filename)
{
	std::cout << "Loading Board!!\n";
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			gameState = 0;
			showingBomb = 0;
			array2D[i][j].setIsShown(0);
			array2D[i][j].setIsFlag(0);
			array2D[i][j].setIsMine(0);
			array2D[i][j].setNearByMines(0);
		}
	}
	
	std::ifstream inFS(filename);
	if (inFS.is_open())
	{
		flags = 0;
		numBombs = 0;
		std::string mineValue;
		bool mineValueBool;
		for (int i = 0; i < 16; i++)
		{
			getline(inFS, mineValue, '\n');
			for (int j = 0; j < 25; j++)
			{
				//int p = mineValue.at(j);
				mineValueBool = (int)(mineValue.at(j)%48);
				//std::getline(inFS, mineValue, ',')
				array2D[j][i].setIsMine(mineValueBool);
				if (mineValueBool) numBombs++;
			}
		}
		//std::cout << "hi";
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (array2D[i][j].getIsMine())
			{
				if (i != 0)
				{
					if (j != 0)
					{
						array2D[i - 1][j - 1].setNearByMines(array2D[i - 1][j - 1].getNearByMines() + 1);
					}
					if (j != 15)
					{
						array2D[i - 1][j + 1].setNearByMines((array2D[i - 1][j + 1].getNearByMines()) + 1);
					}
					array2D[i - 1][j].setNearByMines(array2D[i - 1][j].getNearByMines() + 1);
				}
				if (i != 24)
				{
					if (j != 0)
					{
						array2D[i + 1][j - 1].setNearByMines(array2D[i + 1][j - 1].getNearByMines() + 1);
					}
					if (j != 15)
					{
						array2D[i + 1][j + 1].setNearByMines(array2D[i + 1][j + 1].getNearByMines() + 1);
					}
					array2D[i + 1][j].setNearByMines(array2D[i + 1][j].getNearByMines() + 1);
				}
				if (j != 0)
				{
					array2D[i][j - 1].setNearByMines(array2D[i][j - 1].getNearByMines() + 1);
				}
				if (j != 15)
				{
					array2D[i][j + 1].setNearByMines(array2D[i][j + 1].getNearByMines() + 1);
				}
			}
		}
	}
	//std::cout << "hi";
}
bool Board::checkWin()
{
	bool flag = true;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 16; j++)
		{/*
			if (array2D[i][j].getIsMine() && array2D[i][j].getIsFlag())
			{
			}
			else if (array2D[i][j].getIsMine() && !array2D[i][j].getIsShown())
			{
			}
			
			else */if (array2D[i][j].getIsMine() || array2D[i][j].getIsShown())
			{
				//flag = false;
			}
			else
			{
				flag = false;
			}
			//if (!array2D[i][j].getIsMine() || !array2D[i][j].getIsFlag() || !array2D[i][j].getIsShown())
			//{
			//	flag = false;
			//}
		}
	}
	if (flag)
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (array2D[i][j].getIsMine())
				{
					array2D[i][j].setIsFlag(true);
				}
			}
		}
	}
	return flag;
}
Board::~Board()
{

}
