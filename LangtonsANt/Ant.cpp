#include "Ant.h"

Ant::Ant() {
	position.x = GRIDWIDTH * (WIDTH / GRIDWIDTH / 2);
	position.y = GRIDHEIGHT * (HEIGHT / GRIDHEIGHT / 2);
	direction = 3;

	antT.loadFromFile(antPic);
	antS.setTexture(antT);

	antS.setOrigin(antT.getSize().x / 2, antT.getSize().y / 2);
	antS.setPosition(this->position.x, this->position.y);
	antS.setRotation(direction * 90);

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
	antS.setPosition(this->position.x + GRIDWIDTH/2 , this->position.y + GRIDHEIGHT/2);
	antS.setRotation(direction * 90);
}

void Ant::GetDirection(int grid[HEIGHT / GRIDHEIGHT][WIDTH / GRIDWIDTH]) {
	direction = grid[position.y / GRIDHEIGHT][position.x / GRIDWIDTH] ?
		(((direction - 1) + 4) % 4) :
		((direction + 1) % 4);
}
