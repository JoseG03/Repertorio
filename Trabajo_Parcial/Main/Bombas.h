#pragma once
#include "Libreria.h"

class Bomba {
private:
	int x, y;
	int dy;
	int width, height;
	bool visible;
public:
	Bomba(int px, int py) {
		x = px;
		y = py;
		dy = 1;
		width = 1;
		height = 1;
		visible = true;
	}
	~Bomba() {}

	//haran visible o no la bomba
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	int getY() { return y; }

	// Erase - Move - Draw

	void erase() {
		Console::SetCursorPosition(x + 3, y + 1); cout << " ";
	}

	void move() {
		y += dy;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x + 3, y + 1); cout << char(206);
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x - 1, y - 1, width + 3, height + 3);
		//▓▓▓▓▓
        //▓▓▓▓▓
		//▓▓╬▓▓
		//▓▓▓▓▓
		//▓▓▓▓▓
	}
};