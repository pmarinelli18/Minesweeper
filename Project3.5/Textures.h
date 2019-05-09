#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
class Textures
{
public:
	std::map<std::string, sf::Texture>  textures;
	int f = 2;
	Textures();
	~Textures();
};
class TexturesRect
{
	public:
		std::map<std::string, sf::Texture>  textures;
		//TexturesRect();
		//~TexturesRect();
};

