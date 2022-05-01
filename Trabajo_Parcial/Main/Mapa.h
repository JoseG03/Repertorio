#pragma once
#include "Libreria.h"

class Bloque {
private:
    int x, y;
    int width, height;
    bool visible;
public:
    Bloque(int px, int py) {
        x = px; y = py;
        width = height = 1;
        visible = true;
    }
    ~Bloque(){}

    void draw() {

        Console::SetCursorPosition(x, y); cout << (char)178;
    }
    System::Drawing::Rectangle getRectangle() {
        return System::Drawing::Rectangle(x, y, width, height);
    }
};

class Mapa {
private:
    char* fondocielo;
    char* fondotierra;
    char* cueva2;
    char* cueva1;
public:
    Mapa() {
        fondocielo = new char(178);
        fondotierra = new char(178);
        cueva2 = new char(178);
        cueva1 = new char(178);
    }
    void fondo() {
        for (int filas = 0; filas < 4; filas++)
        {
            for (int columnas = 0; columnas < ANCHOESCENARIO; columnas++)
            {
                Console::SetCursorPosition(columnas + 0, filas + 0);
                Console::ForegroundColor = ConsoleColor::Blue;
                cout << *fondocielo;
            }
        }


        for (int filas = 4; filas < ALTURAESCENARIO; filas++)
        {
            for (int columnas = 0; columnas < ANCHOESCENARIO; columnas++)
            {
                Console::SetCursorPosition(columnas + 0, filas + 0);
                Console::ForegroundColor = ConsoleColor::Yellow;
                cout << *fondotierra;
            }
        }


        for (int filas = 32; filas < 36; filas++)
        {
            for (int columnas = 8; columnas < 35; columnas++)
            {
                Console::SetCursorPosition(columnas + 0, filas + 0);
                Console::ForegroundColor = ConsoleColor::Black;
                cout << *fondotierra;
            }
        }


        for (int filas = 10; filas < 14; filas++)
        {
            for (int columnas = 50; columnas < 77; columnas++)
            {
                Console::SetCursorPosition(columnas + 0, filas + 0);
                Console::ForegroundColor = ConsoleColor::Black;
                cout << *fondotierra;
            }
        }
    }
};