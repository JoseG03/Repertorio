#pragma once
#include "Libreria.h"
#include "Excavador.h"
#include "Corazon.h"
#include "El Pocas.h"
#include "El Fygars.h"
#include "Bombas.h"
#include "Mapa.h"

//clase controladora
class Escenario {
private:
	Excavador* ben;
	libreria* comando;
	vector <Corazon*> corazon;
	vector <Pocas*> pocas;
	vector <Fygars*> fygars;
	vector <Bomba*> bomba;
	vector <Bloque*> ladrillo;
	int hp;
public:
	Escenario() {
		ben = new Excavador();
		hp = 3;
	}
	~Escenario(){}

	//se agrega un nuevo objeto corazon
	void addCorazon() {
		if(corazon.size()<3)
		corazon.push_back(new Corazon());
	}
	void addEnemigo() {
		if (pocas.size() < 2) {
			pocas.push_back(new Pocas());
		}
		if (fygars.size() < 2) {
			fygars.push_back(new Fygars());
		}
	}
	void addBomba() {
		bomba.push_back(new Bomba(ben->getX(), ben->getY()));
	}

	void addLadrillo(int x, int y) {
		ladrillo.push_back(new Bloque(x, y));
	}

	//Erase - Move - Draw
	void BorrarTodo() {
		for (int i = 0; i < corazon.size(); i++) {
			corazon[i]->erase();
		}
		for (int i = 0; i < pocas.size(); i++) {
			pocas[i]->erase(1);
		}
		for (int i = 0; i < fygars.size(); i++) {
			fygars[i]->erase(2);
		}
		for (int i = 0; i < bomba.size(); i++) {
			bomba[i]->erase();
		}
		ben->erase();
	}
	void MoverTodo() {//permite que se mueva automaticamente
		for (int i = 0; i < corazon.size(); i++) {
			corazon[i]->move();
		}
		for (int i = 0; i < pocas.size(); i++) {
			pocas[i]->move(1);
		}
		for (int i = 0; i < fygars.size(); i++) {
			fygars[i]->move(2);
		}
		for (int i = 0; i < bomba.size(); i++) {
			bomba[i]->move();
		}
	}
	void DibujarTodo() {
		for (int i = 0; i < corazon.size(); i++) {
			corazon[i]->draw();
		}
		for (int i = 0; i < pocas.size(); i++) {
			pocas[i]->draw(1);
		}
		for (int i = 0; i < fygars.size(); i++) {
			fygars[i]->draw(2);
		}
		for (int i = 0; i < bomba.size(); i++) {
			bomba[i]->draw();
		}
		ben->draw();
	}

	//colision entre objetos
	void colision() {
		//verifica la colision y la accion a realizar
		for (int i = 0; i < corazon.size(); i++) {
			if (ben->getRectangle().IntersectsWith(corazon[i]->getRectangle())) {
				if (hp < 5) {
				corazon[i]->setVisible(false);
				hp++;
				}
			}
		}
		for (int i = 0; i < pocas.size(); i++) {
			if (ben->getRectangle().IntersectsWith(pocas[i]->getRectangle())) {
				ben->setX(10 + rand() % 60);
				ben->setY(10 + rand() % 30);
				hp--;
			}
		}
		for (int i = 0; i < fygars.size(); i++) {
			if (ben->getRectangle().IntersectsWith(fygars[i]->getRectangle())) {
				ben->setX(10 + rand() % 60);
				ben->setY(10 + rand() % 30);
				hp--;
			}
		}

		//elimina el objeto una vez deje de ser visible
		for (int i = 0; i < corazon.size(); i++) {
			if (corazon[i]->getVisible() == false) {
				corazon.erase(corazon.begin() + i);
			}
		}
	}

	void colisionBomba() {
		//verificador de colision con enemigos
		for (int i = 0; i < pocas.size(); i++) {
			for (int j = 0; j < bomba.size(); j++) {
				if (bomba[j]->getRectangle().IntersectsWith(pocas[i]->getRectangle())) {
					bomba[j]->setVisible(false);
					pocas[i]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < fygars.size(); i++) {
			for (int j = 0; j < bomba.size(); j++) {
				if (bomba[j]->getRectangle().IntersectsWith(fygars[i]->getRectangle())) {
					bomba[j]->setVisible(false);
					fygars[i]->setVisible(false);
				}
			}
		}
		//verificador de colision con el limite
		for (int i = 0; i < bomba.size(); i++) {
			if (bomba[i]->getY() > 37) {
				bomba[i]->setVisible(false);
			}
		}
		for (int i = 0; i < fygars.size(); i++) {
			if (fygars[i]->getY() < 5) {
				fygars[i]->setVisible(false);
			}
		}
		for (int i = 0; i < pocas.size(); i++) {
			if (pocas[i]->getY() < 5) {
				pocas[i]->setVisible(false);
			}
		}

		//elimina el objeto
		for (int i = 0; i < bomba.size(); i++) {
			if (bomba[i]->getVisible() == false) {
				bomba.erase(bomba.begin() + i);
			}
		}
		for (int i = 0; i < pocas.size(); i++) {
			if (pocas[i]->getVisible() == false) {
				pocas.erase(pocas.begin() + i);
			}
		}
		for (int i = 0; i < fygars.size(); i++) {
			if (fygars[i]->getVisible() == false) {
				fygars.erase(fygars.begin() + i);
			}
		}
	}

	//obtenemos las funciones de la clase excavador
	Excavador* getExcavador() { return ben; }
	int getHp() { return hp; }//regresa el numero de vidas
};