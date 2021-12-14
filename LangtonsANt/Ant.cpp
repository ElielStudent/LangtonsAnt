#include "Ant.h"

Ant::Ant() {
	position.x = WIDTH / 2;
	position.y = HEIGHT / 2;
	antS.setPosition(this->position.x, this->position.y);
	direction = 3;

	antT.loadFromFile(antPic);
	antS.setTexture(antT);

	float xScale = float(GRIDWIDTH) / float(antT.getSize().x);
	float yScale = float(GRIDHEIGHT) / float(antT.getSize().y);
	antS.setScale(xScale, yScale);
}

void Ant::Move(int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH]) {

	GetDirection(grid);
	grid[position.y / GRIDHEIGHT][position.x / GRIDWIDTH] = !grid[position.y / GRIDHEIGHT][position.x / GRIDWIDTH];
	if (direction == 0) this->position.y -= GRIDHEIGHT;
	else if (direction == 2) this->position.y += GRIDHEIGHT;
	else if (direction == 1) this->position.x += GRIDWIDTH;
	else if (direction == 3) this->position.x -= GRIDWIDTH;
	//this->position += { ((direction / 2 * 2 - 1)* (direction % 2))* GRIDWIDTH,
	//	(direction - 1 * (direction % 2 == 0))* GRIDHEIGHT}; //1 x++ | 3 x--  ||  0 y-- | 2 y++
	antS.setRotation(direction * 90);
	antS.setPosition(this->position.x, this->position.y);
}

void Ant::GetDirection(int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH]) {
	direction = grid[position.y / GRIDHEIGHT][position.x / GRIDWIDTH] ?
		(((direction - 1) + 4) % 4) :
		((direction + 1) % 4);
}
