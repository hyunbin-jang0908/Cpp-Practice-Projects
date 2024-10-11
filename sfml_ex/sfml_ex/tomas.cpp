#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

void tomas() {
	// Create the window
	RenderWindow window(sf::VideoMode(800, 480), "LUNAR LANDER");
	window.setFramerateLimit(60);

	Texture t1;
	Sprite background;
	t1.loadFromFile("images/space_background.png");
	background.setTexture(t1);

	// Create sprite for the game
	Texture t2;
	Sprite lander;
	t2.loadFromFile("images/spaceship1.png");
	lander.setTexture(t2);

	// Game loop
	while (window.isOpen()) {
		// Event check and processing
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
				lander.move(-10.0, 0.0);
			if (Keyboard::isKeyPressed(Keyboard::Right))
				lander.move(10.0, 0.0);
			if (Keyboard::isKeyPressed(Keyboard::Up))
				lander.move(0.0, -10.0);
			if (Keyboard::isKeyPressed(Keyboard::Down))
				lander.move(0.0, 10.0);
		}

		// Clear window
		window.clear();
		// Draw the sprite obn the window
		window.draw(background);
		window.draw(lander);
		// Show the window
		window.display();
	}

}