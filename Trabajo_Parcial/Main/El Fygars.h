#pragma once
#include "Enemigo.h"

class Fygars : public Enemigo //Indicamos que es hija de enemigo
{
public:
	Fygars():Enemigo(){}
	~Fygars(){}
	int getX(){ return this->x1; }
	int getY() { return this->y1; }
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x1, y1, width + 2, height);
	}
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};