#pragma once
#include "Libreria.h"

class Corazon {
private:
	int x, y;
	int dx, dy;
	int width, height;
	bool visible;
public:
	Corazon() {
		x = 10 + rand() % 60;
		y = 5 + rand() % 30;
		dx = 1;
		width = 1;
		height = 2;
		visible = true;
	}
	~Corazon(){}

	//haran visible o no el corazon
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	// Erase - Move - Draw
	void erase() {
		Console::SetCursorPosition(x, y); cout << " ";
	}
	void move() {
		if (x < 1 || x + width > 79) {
			dx *= -1;
		}
		x += dx;
	}
	void draw() {
		Console::SetCursorPosition(x, y); cout << char(219);
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, width, height);
	}
};