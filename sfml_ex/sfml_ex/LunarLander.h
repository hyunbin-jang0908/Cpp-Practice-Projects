#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <vector>
using namespace sf;
using namespace std;

class LunarLander {
private:
	double x, y;
	double velocity;
	double fuel;
	string status;
	Texture t1, t2;
	Sprite spaceship, burst;
	Font font;
	Text text;
public:
	LunarLander(double h, double v, double f);
	bool checkLanded();
	void update(double rate);
	void draw(RenderWindow& window);
};
