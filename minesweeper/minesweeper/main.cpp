#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <string>
using namespace sf;
using namespace std;

class Tile {
public:
	bool open;
	int number;
};

const int TILE_SIZE = 40;

// represents status of the tile
const int BOMB = 9;
const int HIDDEN = 10;

int main() {
	srand(time(NULL));
	RenderWindow app(VideoMode(500, 500), "Minesweeper");

	Tile grid[12][12];
	bool game_ended = false;

	Sprite sprites[12];
	Texture t[12];
	for (int k = 0; k < 12; k++) {
		t[k].loadFromFile("images/tile" + to_string(k) + ".png");
		sprites[k].setTexture(t[k]);
	}

	// Store mines on the board
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			grid[i][j].open = false;
			grid[i][j].number = 0;
			if ((rand() % 10) == 1)
				grid[i][j].number = BOMB; // 9
		}
	}

	// Calculate the number of adjacent mines
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			int n = 0;
			if (grid[i][j].number == BOMB) continue;
			if (grid[i+1][j].number == BOMB) n++;
			if (grid[i][j+1].number == BOMB) n++;
			if (grid[i-1][j].number == BOMB) n++;
			if (grid[i][j-1].number == BOMB) n++;
			if (grid[i+1][j+1].number == BOMB) n++;
			if (grid[i+1][j-1].number == BOMB) n++;
			if (grid[i-1][j-1].number == BOMB) n++;
			if (grid[i-1][j+1].number == BOMB) n++;
			grid[i][j].number = n;
		}
	}

	// main loop
	while (app.isOpen())
	{
		// Get the number of the tile where cursor is on
		Vector2i pos = Mouse::getPosition(app);
		int x = pos.x / TILE_SIZE;
		int y = pos.y / TILE_SIZE;

		// Process the event
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();

			// Left click -> show the number
			if (e.type == Event::MouseButtonPressed) {
				grid[x][y].open = true;
				if (grid[x][y].number == BOMB) game_ended = true;
			}
		}

		// Draw the game board
		app.clear(Color::White);
		// Actual game board is 10x10
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				int n;
				// depends on the status of the tile, assign an image
				// if game has ended, open every tile.
				if (!grid[i][j].open && !game_ended)
					n = HIDDEN;
				else
					n = grid[i][j].number;
				sprites[n].setPosition(TILE_SIZE * i, TILE_SIZE * j);
				app.draw(sprites[n]);
			}
		}
		app.display();
	}

	return 0;
}