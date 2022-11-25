#pragma once

#include "Window.hpp"
#include "Entity.hpp"

namespace Manager
{
	class GraphicManager
	{
	private:
		Window* pWindow;
		GraphicManager();
		GraphicManager(Window* pW);
		float deltaTime;
		sf::Clock clock;

		static GraphicManager* instance;

		std::map<std::string, sf::Texture*> textureMap;

	public:

		~GraphicManager();

		static GraphicManager* getInstance();

		void setWindow(Window* pW);

		Window* getWindow();

		float updateDeltaTime();

		const float getDeltaTime() const;

		//void print();
		void printEntity(Entity* pE);
		void printText(sf::Text* pT);

		sf::Texture* loadTexture(std::string filePath);

		void clear();
		void display();
	};
}

