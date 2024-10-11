#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include "LunarLander.h"
using namespace sf;
using namespace std;

LunarLander::LunarLander(double h, double v, double f) {
	x = 300;
	y = h;
	velocity = v;
	fuel = f;
	t1.loadFromFile("images/rocket.png");
	t2.loadFromFile("images/burst.png");
	spaceship.setTexture(t1);
	burst.setTexture(t2);
	spaceship.setPosition(x, y);
	burst.setPosition(x + 38, y + 80);
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "Cannot open the font file.";
	}
	text.setFont(font);
}

// Check if it has landed - if height <= 0
bool LunarLander::checkLanded() {
	return y >= 515;
}

// Update the game status
void LunarLander::update(double amount) {
	// When it reaches the ground
	if (amount == -1) {
		status = "Press up key!\nheight: " + to_string(y) + "\nspeed: " +
			to_string(velocity) + "\nfuel: " + to_string(fuel);
		if (velocity > 10)
			status += "\nFAIL. Speed too high.";
		else
			status += "\nLanded successfully!";
		return;
	}
	if (fuel <= 0) {
		fuel = 0;
		amount = 0; // ran out of fuel, no thrust
	}
	fuel -= amount;
	velocity -= amount - 0.5;
	y += velocity;
	if (y > 515) y = 515;
	spaceship.setPosition(x, y);
	if (amount == 0)
		burst.setPosition(900, 900); // so the burst is not shown in the window.
	else
		burst.setPosition(x + 38, y + 80);
	status = "Press up key!\nheight: " + to_string(y) + "\nspeed: " +
		to_string(velocity) + "\nfuel: " + to_string(fuel);
}

// Draw spaceship, burst, current status
void LunarLander::draw(RenderWindow& window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}
