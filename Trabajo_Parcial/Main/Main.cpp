#include "pch.h"
#include "Libreria.h"
#include "Controlador.h"
#include "Mapa.h"

int main()
{
    srand(time(NULL));
    Console::SetWindowSize(80, 40);
    Escenario* controlador = new Escenario();
    libreria* comandos = new libreria();
    char key;
    int segundo = 0;

    while (1) {
        Console::CursorVisible = false;
        //escribe las vidas arriba de la pantalla
        Console::ForegroundColor = ConsoleColor::White;
        comandos->gotoxy(1, 1); cout << "Vidas: " << controlador->getHp();

        //terminara el juego si las vidas llegan a 0
        if (controlador->getHp() == 0)break;

        //Console::ForegroundColor = ConsoleColor::Green;
        //for (int i = 0; i < 80; i++) {
        //    for (int j = 0; j < 5; j++) {
        //        controlador->addLadrillo(i, j);
        //    }
        //}

        controlador->BorrarTodo();
        controlador->colision();
        if (_kbhit()) {
            key = _getch();
            key = toupper(key);
            controlador->getExcavador()->move(key);
            if (key == 'B')controlador->addBomba();
        }

        controlador->colisionBomba();

        controlador->addCorazon();
        controlador->addEnemigo();

        controlador->MoverTodo();
        controlador->DibujarTodo();


        _sleep(50);
    }

    system("cls");
    cout << "Estuvo bueno pero ya volvio el internet";
    _getch();
    return 0;
}
