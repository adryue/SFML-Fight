#include <iostream>
#include <SFML/Graphics.hpp>
#include "CommonDef.h"
#include "Fighter.h"

const int WIN_X_LEN = 800;
const int WIN_Y_LEN = 600;
const int FRAMERATE = 60;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIN_X_LEN, WIN_Y_LEN), "FIGHT WOOOO");
	window.setFramerateLimit(FRAMERATE);


	Fighter f1(0, sf::Vector2f(200, 300));
	Fighter f2(1, sf::Vector2f(600, 300));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();

		f1.handleInput();
		f2.handleInput();

		/*std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << " " << sf::Joystick::getAxisPosition(0, sf::Joystick::Y) << " " << sf::Joystick::getAxisPosition(0, sf::Joystick::Z) << " " << sf::Joystick::getAxisPosition(0, sf::Joystick::R);
		for (int i = 0; i < 16; i++)
		{
			if (sf::Joystick::isButtonPressed(0, i))
			{
				std::cout << " Button " << i << " pressed";
			}
		}
		std::cout << "\n";*/

		f1.draw(window);
		f2.draw(window);

		window.display();
	}

	return 0;
}