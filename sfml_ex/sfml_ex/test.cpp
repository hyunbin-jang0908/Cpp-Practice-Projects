#include <iostream>
#include <SFML/Graphics.hpp>

int test() 
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) // Event�� ó��������̸� true
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear the window then draw again
		window.clear();
		window.draw(shape);
		window.display();
	}

		return 0;
}
