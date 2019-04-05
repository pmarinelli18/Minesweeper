#include "Textures.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


Textures::Textures()
{
	sf::Texture debugT;
	debugT.loadFromFile("images/debug.png");
	sf::Texture digitsT;
	digitsT.loadFromFile("images/digits.png");
	sf::Texture faceHappyT;
	faceHappyT.loadFromFile("images/face_happy.png");
	sf::Texture faceLoseT;
	faceLoseT.loadFromFile("images/face_lose.png");
	sf::Texture faceWinT;
	faceWinT.loadFromFile("images/face_win.png");
	sf::Texture flagT;
	flagT.loadFromFile("images/flag.png");
	sf::Texture mineT;
	mineT.loadFromFile("images/mine.png");
	sf::Texture number1T;
	number1T.loadFromFile("images/number_1.png");
	sf::Texture number2T;
	number2T.loadFromFile("images/number_2.png");
	sf::Texture number3T;
	number3T.loadFromFile("images/number_3.png");
	sf::Texture number4T;
	number4T.loadFromFile("images/number_4.png");
	sf::Texture number5T;
	number5T.loadFromFile("images/number_5.png");
	sf::Texture number6T;
	number6T.loadFromFile("images/number_6.png");
	sf::Texture number7T;
	number7T.loadFromFile("images/number_7.png");
	sf::Texture number8T;
	number8T.loadFromFile("images/number_8.png");
	sf::Texture test1T;
	test1T.loadFromFile("images/test_1.png");
	sf::Texture test2T;
	test2T.loadFromFile("images/test_2.png");
	sf::Texture test3T;
	test3T.loadFromFile("images/test_3.png");
	sf::Texture tileHiddenT;
	tileHiddenT.loadFromFile("images/tile_hidden.png");
	sf::Texture tileRevealedT;
	tileRevealedT.loadFromFile("images/tile_revealed.png");

	textures = std::map<std::string, sf::Texture>();

	textures["debug"] = debugT;
	textures["digits"] = digitsT;
	textures["faceHappy"] = faceHappyT;
	textures["faceLose"] = faceLoseT;
	textures["faceWin"] = faceWinT;
	textures["flag"] = flagT;
	textures["mine"] = mineT;
	textures["number1"] = number1T;
	textures["number2"] = number2T;
	textures["number3"] = number3T;
	textures["number4"] = number4T;
	textures["number5"] = number5T;
	textures["number6"] = number6T;
	textures["number7"] = number7T;
	textures["number8"] = number8T;
	textures["test1"] = test1T;
	textures["test2"] = test2T;
	textures["test3"] = test3T;
	textures["tileHidden"] = tileHiddenT;
	textures["tileRevealed"] = tileRevealedT;
}


Textures::~Textures()
{
}
