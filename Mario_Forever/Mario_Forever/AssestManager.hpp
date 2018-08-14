#pragma once
#include<map>
#include<SFML\Graphics.hpp>
namespace abay
{
	class AssetManager
	{
	public :
		AssetManager(){}
		~AssetManager(){}

		void LoadTexture(std::string name, std::string Filename);
		sf::Texture &GetTexture(std::string name);
		void LoadFont(std::string name, std::string Filename);
		sf::Font &GetFont(std::string name);
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;





	};



}