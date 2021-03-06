// DungeonGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DungeonControl.h"
#include <vector>


DungeonControl g_DungeonController;
int g_width = 1200;
int g_height = 900;

int main()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(g_width, g_height), "SFML works!");
	g_DungeonController.SetMapCenter(g_width, g_height);
	

	while (window.isOpen())
	{
		sf::Event event;
	
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					g_DungeonController.GenerateRooms(&window);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					g_DungeonController.ComputeSeparation();
					std::cout << "No morí prro :v" << std::endl;
				}
				//rect.setPosition(sf::Vector2f(rand() % 700 + 100, rand() % 500 + 100));
				break;
			}
		}

		window.clear();
		for (auto currentRoom : g_DungeonController.m_roomsInGrid)
		//for (int i = 0; i < g_DungeonController.m_roomsInGrid.size(); i++)
		{
			window.draw(currentRoom.m_cellRectangle);
			window.draw(currentRoom.m_Node);
		}

		
		window.display();

	}

	return 0;
}


