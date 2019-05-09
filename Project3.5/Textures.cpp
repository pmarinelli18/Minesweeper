#include "Textures.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


Textures::Textures()
{
	textures = std::map<std::string, sf::Texture>();
	sf::Texture debugT;
	debugT.loadFromFile("images/debug.png");
	sf::Texture faceHappyT;
	faceHappyT.loadFromFile("images/face_happy.png");//"images/face_happy3.png"
	sf::Texture faceLoseT;
	faceLoseT.loadFromFile("images/face_lose.png");//"images/face_lose3.png"
	sf::Texture faceWinT;
	faceWinT.loadFromFile("images/face_win.png");//"images/face_win3.png"
	sf::Texture flagT;
	flagT.loadFromFile("images/flag.png");//images/flag2.png
	sf::Texture mineT;
	mineT.loadFromFile("images/mine.png");//images/mines2.png
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
	sf::Texture digitsT;
	digitsT.loadFromFile("images/digits.png");
	/*
	sf::Texture digits0T;
	
	textures["digits0"] = digits0T;
	digits0T.loadFromFile("images/digits.png", sf::IntRect(0, 0, 21, 32));
	sf::Texture digits1T;
	textures["digits1"] = digits1T;
	digits1T.loadFromFile("images/digits.png", sf::IntRect(21, 0, 21, 32));
	sf::Texture digits2T;
	textures["digits2"] = digits2T;
	digits2T.loadFromFile("images/digits.png", sf::IntRect(42, 0, 21, 32));
	sf::Texture digits3T;
	textures["digits3"] = digits3T;
	digits3T.loadFromFile("images/digits.png", sf::IntRect(63, 0, 21, 32));
	sf::Texture digits4T;
	textures["digits4"] = digits4T;
	digits4T.loadFromFile("images/digits.png", sf::IntRect(84, 0, 21, 32));
	sf::Texture digits5T;
	textures["digits5"] = digits5T;
	digits5T.loadFromFile("images/digits.png", sf::IntRect(105, 0, 21, 32));
	sf::Texture digits6T;
	textures["digits6"] = digits6T;
	digits6T.loadFromFile("images/digits.png", sf::IntRect(126, 0, 21, 32));
	sf::Texture digits7T;
	textures["digits7"] = digits7T;
	digits7T.loadFromFile("images/digits.png", sf::IntRect(147, 0, 21, 32));
	sf::Texture digits8T;
	textures["digits8"] = digits8T;
	digits8T.loadFromFile("images/digits.png", sf::IntRect(168, 0, 21, 32));
	sf::Texture digits9T;
	textures["digits9"] = digits9T;
	digits9T.loadFromFile("images/digits.png", sf::IntRect(189, 0, 21, 32));
	sf::Texture digitsDT;
	digitsDT.loadFromFile("images/digits.png", sf::IntRect(210, 0, 21, 32));
	textures["digitsD"] = digitsDT;
	
	*/

	textures["debug"] = debugT;
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
	textures["digits"] = digitsT;
	/*textures["digits1"] = digits1T;
	textures["digits2"] = digits2T;
	textures["digits3"] = digits3T;
	textures["digits4"] = digits4T;
	textures["digits5"] = digits5T;
	textures["digits6"] = digits6T;
	textures["digits7"] = digits7T;
	textures["digits8"] = digits8T;
	textures["digits9"] = digits9T;
	//textures["digitsD"] = digitsDT;*/
}


Textures::~Textures()
{
}
