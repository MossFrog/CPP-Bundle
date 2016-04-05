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

	//-- Disable Key Repetition to enable button pressed events. --//
	mainWindow.setKeyRepeatEnabled(false);

	//-- Declarations Section --//
	//--------------------------//

	sf::Texture gemTexture;
	gemTexture.loadFromFile("SphereGem.png");

	sf::Sprite gemSprite;
	gemSprite.setTexture(gemTexture);
	gemSprite.setOrigin(8, 8);
	gemSprite.setScale(5, 5);





	//-- Main Game Loop --//
	while (mainWindow.isOpen())
	{
		//-- Event Methods --//
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}

		sf::Vector2i localPosition = sf::Mouse::getPosition(mainWindow);

		//cout << localPosition.x << " " << localPosition.y << endl;

		gemSprite.setPosition(localPosition.x,localPosition.y);


		mainWindow.clear(sf::Color::Black);

		mainWindow.draw(gemSprite);

		mainWindow.display();
	}

	//-- END PROGRAM --//
	return 0;
}