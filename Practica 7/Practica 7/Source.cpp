#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

// Clase Registro con los atributos indicados
class Registro {
public:
    std::string iso_code;
    std::string continent;
    std::string location;
    int total_cases;
    int total_deaths;
    double total_cases_per_million;
    double total_deaths_per_million;

    Registro(const std::string& iso_code, const std::string& continent, const std::string& location,
        int total_cases, int total_deaths, double total_cases_per_million, double total_deaths_per_million)
        : iso_code(iso_code), continent(continent), location(location), total_cases(total_cases),
        total_deaths(total_deaths), total_cases_per_million(total_cases_per_million),
        total_deaths_per_million(total_deaths_per_million) {}
};

// Clase Diagnostico
class Diagnostico {
private:
    std::list<Registro> registros;  // Lista de registros

public:
    // Método para agregar un registro a la lista
    void agregarRegistro() {
        std::string iso_code, continent, location;
        int total_cases, total_deaths;
        double total_cases_per_million, total_deaths_per_million;

        std::cout << "Ingrese los datos del registro:" << std::endl;
        std::cout << "iso_code: ";
        std::cin >> iso_code;
        std::cout << "continent: ";
        std::cin >> continent;
        std::cout << "location: ";
        std::cin >> location;
        std::cout << "total_cases: ";
        std::cin >> total_cases;
        std::cout << "total_deaths: ";
        std::cin >> total_deaths;
        std::cout << "total_cases_per_million: ";
        std::cin >> total_cases_per_million;
        std::cout << "total_deaths_per_million: ";
        std::cin >> total_deaths_per_million;

        registros.emplace_back(iso_code, continent, location, total_cases, total_deaths,
            total_cases_per_million, total_deaths_per_million);

        std::cout << "Registro agregado correctamente." << std::endl;
    }

    // Método para mostrar la cantidad de registros y el país con más y menos casos
    void mostrarEstadisticas() {
        std::cout << "Cantidad de registros: " << registros.size() << std::endl;

        auto maxCasesCountry = std::max_element(registros.begin(), registros.end(),
            [](const Registro& reg1, const Registro& reg2) {
                return reg1.total_cases < reg2.total_cases;
            });
        std::cout << "Pais con mas casos: " << maxCasesCountry->location << std::endl;

        auto minCasesCountry = std::min_element(registros.begin(), registros.end(),
            [](const Registro& reg1, const Registro& reg2) {
                return reg1.total_cases < reg2.total_cases;
            });
        std::cout << "Pais con menos casos: " << minCasesCountry->location << std::endl;
    }

    // Método para obtener los 5 países con la menor cantidad de casos por millón de habitantes
    void obtenerMenorCantidadCasosPorMillon() {
        std::priority_queue<Registro, std::vector<Registro>, std::function<bool(const Registro&, const Registro&)>> pq(
            [](const Registro& reg1, const Registro& reg2) {
                return reg1.total_cases_per_million > reg2.total_cases_per_million;
            });

        for (const auto& registro : registros) {
            pq.push(registro);
        }

        std::cout << "Paises con la menor cantidad de casos por millon de habitantes:" << std::endl;
        for (int i = 0; i < 5; ++i) {
            if (!pq.empty()) {
                std::cout << pq.top().location << std::endl;
                pq.pop();
            }
        }
    }

    // Método para registrar la variable total_cases como la cantidad de elementos de la lista
    void registrarTotalCasos() {
        std::cout << "Cantidad de casos: " << registros.size() << std::endl;
        std::cout << "================================" << std::endl;

        int caso = 1;
        for (const auto& registro : registros) {
            std::cout << "Caso (" << caso << ")" << std::endl;
            std::cout << "iso_code: " << registro.iso_code << std::endl;
            std::cout << "continent: " << registro.continent << std::endl;
            std::cout << "location: " << registro.location << std::endl;
            std::cout << "total_cases: " << registro.total_cases << std::endl;
            std::cout << "total_deaths: " << registro.total_deaths << std::endl;
            std::cout << "total_cases_per_million: " << registro.total_cases_per_million << std::endl;
            std::cout << "total_deaths_per_million: " << registro.total_deaths_per_million << std::endl;
            std::cout << std::endl;
            caso++;
        }
    }
};

int main() {
    Diagnostico diagnostico;

    int opcion;
    do {
        system("cls");
        std::cout << "===== MENU =====" << std::endl;
        std::cout << "1. Agregar registro" << std::endl;
        std::cout << "2. Mostrar estadisticas" << std::endl;
        std::cout << "3. Obtener paises con menor cantidad de casos por millon" << std::endl;
        std::cout << "4. Registrar la cantidad total de casos" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            diagnostico.agregarRegistro();
            break;
        case 2:
            diagnostico.mostrarEstadisticas();
            break;
        case 3:
            diagnostico.obtenerMenorCantidadCasosPorMillon();
            break;
        case 4:
            diagnostico.registrarTotalCasos();
            break;
        case 5:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
            break;
        }

        std::cout << std::endl;
        system("pause");
    } while (opcion != 5);

    return 0;
}
