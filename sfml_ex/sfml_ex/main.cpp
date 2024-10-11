#include <iostream>
#include "LunarLander.h"
using namespace std;

void tomas();

int main() {

	//tomas();
	RenderWindow window(VideoMode(600, 600), "LUNAR LANDER");
	window.setFramerateLimit(60);

	Texture t;
	Sprite background;
	t.loadFromFile("images/space_background.png");
	background.setTexture(t);

	LunarLander lander(300.0, 1.0, 100.0);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		if (lander.checkLanded()) {
			lander.update(-1);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
			lander.update(3.0);
		else
			lander.update(0.0);

		window.clear();
		window.draw(background);
		lander.draw(window);

		window.display();
		Sleep(100);
	}

	return 0;
}