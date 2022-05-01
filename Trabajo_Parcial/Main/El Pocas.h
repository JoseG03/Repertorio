#pragma once
#include "Enemigo.h"

class Pocas : public Enemigo //Indicamos que es hija de enemigo
{
public:
	Pocas():Enemigo(){}
	~Pocas(){}
	int getX(){ return this->x; }
	int getY() { return this->y; }
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, width, height);
	}
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};