#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void leerArchivoCSV(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file) {
        std::cout << "El archivo no existe. Se creará uno nuevo." << std::endl;
        std::ofstream newFile(archivo);  // Crear nuevo archivo
        newFile.close();
        return;
    }

    std::string line;
    std::cout << "Contenido del archivo CSV:" << std::endl;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> row;

        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }

        for (const auto& data : row) {
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }

    file.close();
}

void agregarContenidoCSV(const std::string& archivo) {
    std::ofstream file(archivo, std::ios::app);  // Abrir el archivo en modo append

    std::string iso_code, continent, location;
    int total_cases, total_deaths;
    double total_cases_per_million, total_deaths_per_million;

    std::cout << "Añadir contenido al archivo CSV:" << std::endl;
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

    file << iso_code << "," << continent << "," << location << "," << total_cases << "," << total_deaths << ","
        << total_cases_per_million << "," << total_deaths_per_million << std::endl;

    file.close();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpiar el buffer de entrada
}

int main() {
    std::string archivoCSV = "datos.csv";  // Reemplaza "datos.csv" por el nombre de tu archivo CSV

    agregarContenidoCSV(archivoCSV);
    leerArchivoCSV(archivoCSV);
    system("pause");
    return 0;
}
