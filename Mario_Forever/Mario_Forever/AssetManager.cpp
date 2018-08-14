#include"stdafx.h"
#include"AssestManager.hpp"
namespace abay
{
	void AssetManager::LoadTexture(std::string name, std::string Filename)

	{
		sf::Texture tex;
		if (tex.loadFromFile(Filename))
		{
			this->_textures[name] = tex;
		}
	}
	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return  this->_textures.at(name);


	}
	void AssetManager::LoadFont(std::string name, std::string Filename)

	{
		sf::Font font;
		if (font.loadFromFile(Filename))
		{
			this->_fonts[name] = font;
		}
	}
	sf::Font &AssetManager::GetFont(std::string name)
	{
		return  this->_fonts.at(name);


	}

}