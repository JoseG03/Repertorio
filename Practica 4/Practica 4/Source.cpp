#include <iostream>
#include <string>
#include <random>
#include <functional>
#include <cstdlib>
using namespace std;

// Clase Póliza
class Poliza {
public:
    int numero;
    double importe;
    std::string beneficiario;

    Poliza(int& num, double imp, const std::string& ben) : numero(num), importe(imp), beneficiario(ben) {}
};

// Nodo del Árbol
class NodoArbol {
public:
    Poliza* poliza;
    NodoArbol* hijos[4];

    NodoArbol(Poliza* pol) : poliza(pol) {
        for (int i = 0; i < 4; i++) {
            hijos[i] = nullptr;
        }
    }
};

// Árbol con 4 hijos
class ArbolCuatroHijos {
private:
    NodoArbol* raiz;

public:
    ArbolCuatroHijos() : raiz(nullptr) {}

    void insertar(Poliza* poliza) {
        raiz = insertarRec(raiz, poliza);
    }

    NodoArbol* insertarRec(NodoArbol* nodo, Poliza* poliza) {
        if (nodo == nullptr) {
            return new NodoArbol(poliza);
        }

        if (poliza->numero < nodo->poliza->numero) {
            nodo->hijos[0] = insertarRec(nodo->hijos[0], poliza);
        }
        else if (poliza->numero > nodo->poliza->numero) {
            nodo->hijos[3] = insertarRec(nodo->hijos[3], poliza);
        }
        else {
            std::cout << "La poliza con el numero " << poliza->numero << " ya existe." << std::endl;
        }

        return nodo;
    }

    void imprimirEnOrden() {
        imprimirEnOrdenRec(raiz);
    }

    void imprimirEnOrdenRec(NodoArbol* nodo) {
        if (nodo != nullptr) {
            imprimirEnOrdenRec(nodo->hijos[0]);
            std::cout << "Numero de poliza: " << nodo->poliza->numero << ", Importe: " << nodo->poliza->importe << ", Beneficiario: " << nodo->poliza->beneficiario << std::endl;
            imprimirEnOrdenRec(nodo->hijos[1]);
            imprimirEnOrdenRec(nodo->hijos[2]);
            imprimirEnOrdenRec(nodo->hijos[3]);
        }
    }

    void buscarPorNumero(int numero, std::function<void(Poliza*)> callback) {
        buscarPorNumeroRec(raiz, numero, callback);
    }

    void buscarPorNumeroRec(NodoArbol* nodo, int numero, std::function<void(Poliza*)> callback) {
        if (nodo != nullptr) {
            if (nodo->poliza->numero == numero) {
                callback(nodo->poliza);
            }
            else if (numero < nodo->poliza->numero) {
                buscarPorNumeroRec(nodo->hijos[0], numero, callback);
            }
            else {
                buscarPorNumeroRec(nodo->hijos[3], numero, callback);
            }
        }
    }
};

// Función de balanceo
void balancearArbol(ArbolCuatroHijos& arbol) {
    // Implementar la función de balanceo aquí
    // ...
}

// Función de impresión
void imprimirPoliza(Poliza* poliza) {
    std::cout << "Numero de poliza: " << poliza->numero << ", Importe: " << poliza->importe << ", Beneficiario: " << poliza->beneficiario << std::endl;
}

int main() {
    // Crear el árbol
    ArbolCuatroHijos arbol;

    // Crear objetos Póliza con valores aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> impDist(1000.0, 10000.0);
    std::uniform_int_distribution<int> lenDist(5, 10);
    std::uniform_int_distribution<int> charDist(97, 122);

    for (int i = 0; i < 20; i++) {
        int numeroPoliza;
        for (int j = 0; j < 8; j++) {
            numeroPoliza = rand() % 1000;
        }

        double importePoliza = impDist(gen);

        std::string beneficiarioPoliza;
        int len = lenDist(gen);
        for (int j = 0; j < len; j++) {
            beneficiarioPoliza += static_cast<char>(charDist(gen));
        }

        Poliza* poliza = new Poliza(numeroPoliza, importePoliza, beneficiarioPoliza);
        arbol.insertar(poliza);
    }

    // Imprimir el árbol en orden
    std::cout << "Arbol en orden:" << std::endl;
    arbol.imprimirEnOrden();

    // Buscar pólizas por número
    std::cout << std::endl << "Busqueda de polizas por numero:" << std::endl;
    arbol.buscarPorNumero(1, imprimirPoliza);
    arbol.buscarPorNumero(500, imprimirPoliza);

    system("pause");
    return 0;
}
