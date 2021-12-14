#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Ant.h"

using namespace sf;

int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH];

void drawGrid(RenderWindow& window, Ant ant, int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH]) {
	RectangleShape rect;
	rect.setSize({ GRIDWIDTH, GRIDHEIGHT });
	rect.setFillColor(Color::Black);
	for (int y = 0; y < HEIGHT / GRIDHEIGHT; y++) {
		for (int x = 0; x < WIDTH / GRIDWIDTH; x++) {
			if (grid[y][x]) {
				rect.setPosition(x * GRIDWIDTH, y * GRIDHEIGHT);
				window.draw(rect);
			}
		}
	}
	window.draw(ant.antS);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "ANT works!");
	Ant ant;
	while (window.isOpen()){
		window.clear(Color::White);
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		ant.Move(grid);
		drawGrid(window, ant, grid);
		window.display();
	}
	return 0;
}