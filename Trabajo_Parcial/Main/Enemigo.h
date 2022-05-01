#pragma once
#include "Libreria.h"

class Enemigo {
protected:
	int x, y, x1, y1;
	int dx, dy, dx1, dy1;
	int width, height;
	bool visible;
	bool direccion;

public:
	Enemigo() {
		x = rand() % 70;
		y = 10 + rand() % 10;
		x1 = rand() % 70;
		y1 = 35;
		dx = rand() % 2; dy = rand() % 2;
		dx1 = 1; dy1 = -1;
		width = 4;
		height = 5;
		visible = true;
		direccion = true;
	}
	~Enemigo(){}

	void erase(short eleg)
	{
		if (eleg == 1) {
			Console::SetCursorPosition(x, y); cout << "   ";
			Console::SetCursorPosition(x, y + 1); cout << "    ";
			Console::SetCursorPosition(x, y + 2); cout << "    ";
			Console::SetCursorPosition(x, y + 3); cout << "    ";
			Console::SetCursorPosition(x, y + 4); cout << "    ";
		}
		else {
			Console::SetCursorPosition(x1, y1); cout << "   ";
			Console::SetCursorPosition(x1, y1 + 1); cout << "    ";
			Console::SetCursorPosition(x1, y1 + 2); cout << "    ";
			Console::SetCursorPosition(x1, y1 + 3); cout << "    ";
			Console::SetCursorPosition(x1, y1 + 4); cout << "    ";
		}
	}

	void move(short eleg)
	{
		if (eleg == 1) {
			if (x < 1 || x + width > 79) {
				dx *= -1;
			}
			if (dx > 0) { direccion = true; }
			if (dx < 0) { direccion = false; }
			if (y < 1 || y + height > 39) {
				dy *= -1;
			}
			x += dx;
			y += dy;
		}
		else {
			if (x1 < 1 || x1 + width > 79) {
				dx1 *= -1;
			}
			if (dx1 > 0) { direccion = true; }
			if (dx1 < 0) { direccion = false; }
			x1 += dx1;
			y1 += dy1;
		}
	}

	void draw(short eleg)
	{
		if (eleg == 1)
		{
			if (direccion) {
				Console::SetCursorPosition(x, y);     cout << " " << (char)126 << " ";
				Console::SetCursorPosition(x, y + 1); cout << (char)170 << " " << (char)170;
				Console::SetCursorPosition(x, y + 2); cout << (char)219 << (char)219 << (char)219;
				Console::SetCursorPosition(x, y + 3); cout << (char)192 << " " << (char)192;
			}
			else {
				Console::SetCursorPosition(x, y);     cout << " " << (char)126 << " ";
				Console::SetCursorPosition(x, y + 1); cout << (char)170 << " " << (char)170;
				Console::SetCursorPosition(x, y + 2); cout << (char)219 << (char)219 << (char)219;
				Console::SetCursorPosition(x, y + 3); cout << (char)217 << " " << (char)217;

			}
		}

		if (eleg == 2)
		{
			if (direccion) {
				Console::SetCursorPosition(x1, y1);     cout << " " << (char)94 << (char)94 << " ";
				Console::SetCursorPosition(x1, y1 + 1);     cout << " " << (char)254 << (char)254 << " ";
				Console::SetCursorPosition(x1, y1 + 2); cout << (char)254 << (char)254 << (char)254 << (char)254;
				Console::SetCursorPosition(x1, y1 + 3); cout << " " << (char)192 << (char)192 << " ";
			}
			else {
				Console::SetCursorPosition(x1, y1);     cout << " " << (char)94 << (char)94 << " ";
				Console::SetCursorPosition(x1, y1 + 1);     cout << " " << (char)254 << (char)254 << " ";
				Console::SetCursorPosition(x1, y1 + 2); cout << (char)254 << (char)254 << (char)254 << (char)254;
				Console::SetCursorPosition(x1, y1 + 3); cout << " " << (char)217 << (char)217 << " ";
			}
		}
	}
};