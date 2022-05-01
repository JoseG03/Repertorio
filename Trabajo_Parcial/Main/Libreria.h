#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#using <system.drawing.dll>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace System;
using namespace System::Drawing;
#define ALTURAESCENARIO 40
#define ANCHOESCENARIO 80

class libreria {
public:
    void gotoxy(int x, int y) {
        HANDLE hCon; //recupera el identificador de la consola al momento de ejecutarlo
        //tomamos el control de salida de nuestro programa
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);

        //determina las coordenadas que le daremos al set despues
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;

        //se situa en las coordenadas que le hemos indicado
        SetConsoleCursorPosition(hCon, dwPos);
    }
};