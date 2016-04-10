#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;


int main()
{
	//-- Create the render Window --//
	sf::RenderWindow mainWindow(sf::VideoMode(1024, 700), "Kruskal's Minimum Spanning Tree", sf::Style::Close);
	//-- Limit the given framerate --//
	mainWindow.setFramerateLimit(60);
	//-- Disable Key Repetition to enable button pressed events. --//
	mainWindow.setKeyRepeatEnabled(false);

	//-- Declarations Section --//
	//--------------------------//

	sf::Vector2i localPosition;

	sf::Texture gemTexture;
	gemTexture.loadFromFile("SphereGem.png");

	sf::Sprite gemSprite;
	gemSprite.setTexture(gemTexture);
	gemSprite.setOrigin(8, 8);
	gemSprite.setScale(3, 3);

	sf::RectangleShape primitiveLine;

	vector<sf::Vector2i> pointVector;
	

	//-- Main Game Loop --//
	while (mainWindow.isOpen())
	{
		//-- Event Methods --//
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();

			//-- If the specified key is pressed push the player upwards --//
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					bool validPos = false;

					//for (int i = 0; i < ) unfinished method
					//-- Place a pinpoint on the given click (add it to the main vector) --//
					pointVector.push_back(localPosition);
				}
			}
		}

		localPosition = sf::Mouse::getPosition(mainWindow);

		//-- Debugging Section --//
		//cout << localPosition.x << " " << localPosition.y << endl;

		
		mainWindow.clear(sf::Color::Black);


		//-- Draw all the given sprites --//
		for (int i = 0; i < pointVector.size(); i++)
		{
			gemSprite.setPosition(pointVector[i].x, pointVector[i].y);
			mainWindow.draw(gemSprite);



			//-- Render all the weighted lines between the points --//
			for (int j = 0; j < pointVector.size(); j++)
			{
				sf::VertexArray tempLine(sf::Lines, 2);
				
				tempLine[0].position = sf::Vector2f(pointVector[i].x, pointVector[i].y);
				tempLine[1].position = sf::Vector2f(pointVector[j].x, pointVector[j].y);

				tempLine[0].color = sf::Color::Red;
				tempLine[1].color = sf::Color::Blue;
				

				mainWindow.draw(tempLine);
			}
			
		}

		


		mainWindow.display();
	}

	//-- END PROGRAM --//
	return 0;
}