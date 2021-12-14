#pragma once
#include "SFML/Graphics.hpp"
#include "constants.h"

class Ant{
public:
	Ant();
	void Move(int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH]);
	void GetDirection(int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH]);

	sf::Sprite antS;
	sf::Vector2i position;
private:
	sf::Texture antT;
	int direction; //0 90 180 270 || 0 1 2 3 (90*int)
};

