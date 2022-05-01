#pragma once
#include "Libreria.h"

class Excavador {
private:
	int x, y, dx, dy;
	int width, height;
	bool direccion;
public:
	//constructor y destructor
	Excavador() {
		x = 5;
		y = 5;
		dx = 1;
		dy = 1;
		width = 7;
		height = 3;
		direccion = true;
	}
	~Excavador(){}

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }
	int getX() { return x; }
	int getY() { return y; }

	//Erase - Move - Draw

	void erase() {
		Console::SetCursorPosition(x, y);     cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "        ";
		Console::SetCursorPosition(x, y + 2); cout << "       ";
	}

	void move(char key) {
		switch (key)
		{
		//izquierda
		case 75:
			if (x - dx > 0) {
				x -= dx;
				direccion = false;
			} break;
		//derecha
		case 77:
			direccion = true;
			if (x < ANCHOESCENARIO - width) { x += dx; }; break;
		//arriba
		case 72:
			if (y - dy > 0) {
				y -= dy;
			}
			break;
		//abajo
		case 80: 
			if (y < ALTURAESCENARIO - height) { y += dy; } break;
		}
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Red;
		if (direccion) {//esto es si se mueve a la derecha
			Console::SetCursorPosition(x, y);     cout << " O O";
			Console::SetCursorPosition(x, y + 1); cout << "(" << (char)219 << (char)219 << (char)219 << ")-/";
			Console::SetCursorPosition(x, y + 2); cout << " " << (char)192 << " " << (char)192;

		}
		else {//esto si se mueve a la izquierda
			Console::SetCursorPosition(x, y);     cout << "   O O";
			Console::SetCursorPosition(x, y + 1); cout << (char)92 << "-(" << (char)219 << (char)219 << (char)219 << ")";
			Console::SetCursorPosition(x, y + 2); cout << "   "<<(char)217 << " " << (char)217 << " ";
		}
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, width, height);
	}
};