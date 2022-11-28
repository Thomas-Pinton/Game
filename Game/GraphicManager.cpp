#include "GraphicManager.hpp"

namespace Manager {

	GraphicManager::GraphicManager()
	{
		pWindow = NULL;
		deltaTime = 0.0f;
	}

	GraphicManager::GraphicManager(Window* pW)
	{
		pWindow = pW;
		deltaTime = 0.0f;
	}

	GraphicManager::~GraphicManager()
	{
		for (std::map<std::string, sf::Texture*>::iterator paths = textureMap.begin(); paths != textureMap.end(); paths++)
		{
			delete (*paths).second;
		}
		for (std::map<std::string, sf::Font*>::iterator paths = fontMap.begin(); paths != fontMap.end(); paths++)
		{
			delete (*paths).second;
		}
	}

	GraphicManager* GraphicManager::getInstance()
	{
		if (GraphicManager::instance == NULL)
		{
			instance = new GraphicManager;
		}
		return instance;
	}

	void GraphicManager::setWindow(Window* pW)
	{
		pWindow = pW;
	}

	Window* GraphicManager::getWindow()
	{
		return pWindow;
	}

	float GraphicManager::updateDeltaTime()
	{
		deltaTime = (float)clock.restart().asSeconds();

		if (deltaTime > 0.05f)
		{
			deltaTime = 0.05f;
		}
		return deltaTime;
	}

	const float GraphicManager::getDeltaTime() const
	{
		return deltaTime;
	}

	void GraphicManager::printEntity(Entity* pE)
	{
		pWindow->config.draw(pE->rectangle);
	}

	void GraphicManager::printText(sf::Text* pT)
	{
		pWindow->config.draw(*pT);
	}

	void GraphicManager::clear()
	{
		pWindow->config.clear();
	}

	void GraphicManager::display()
	{
		pWindow->config.display();
	}

	sf::Texture* GraphicManager::loadTexture(std::string filePath)
	{
		for (std::map<std::string, sf::Texture*>::iterator paths = textureMap.begin(); paths != textureMap.end(); paths++)
		{
			if ((*paths).first == filePath)
			{
				return (*paths).second;
			}
		}



		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile("../Assets/" + filePath))
		//if (!text->loadFromFile(filePath))

		textureMap.insert({ filePath, text });


		return text;
			
	}

	sf::Font* GraphicManager::loadFont(std::string filePath)
	{
		for (std::map<std::string, sf::Font*>::iterator paths = fontMap.begin(); paths != fontMap.end(); paths++)
		{
			if ((*paths).first == filePath)
			{
				return (*paths).second;
			}
		}



		sf::Font* font = new sf::Font();
		if (!font->loadFromFile("../Assets/" + filePath))
		//if (!text->loadFromFile(filePath))

		fontMap.insert({ filePath, font });


		return font;
			
	}
}