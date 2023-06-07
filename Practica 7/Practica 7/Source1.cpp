//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//#include <limits>
//#include <list>
//
//// Clase Registro
//class Registro {
//public:
//    std::string iso_code;
//    std::string continent;
//    std::string location;
//    int total_cases;
//    int total_deaths;
//    double total_cases_per_million;
//    double total_deaths_per_million;
//
//    Registro(std::string iso_code, std::string continent, std::string location, int total_cases, int total_deaths,
//        double total_cases_per_million, double total_deaths_per_million)
//        : iso_code(iso_code), continent(continent), location(location), total_cases(total_cases),
//        total_deaths(total_deaths), total_cases_per_million(total_cases_per_million),
//        total_deaths_per_million(total_deaths_per_million) {}
//};
//
//// Clase Diagnostico
//class Diagnostico {
//private:
//    std::vector<Registro> registros;
//
//    struct CompareByTotalCasesPerMillion {
//        bool operator()(const Registro* r1, const Registro* r2) const {
//            return r1->total_cases_per_million > r2->total_cases_per_million;
//        }
//    };
//    std::unordered_map<std::string, std::priority_queue<Registro*, std::vector<Registro*>,
//        CompareByTotalCasesPerMillion>>
//        arbol_indices;
//
//public:
//    void cargarDatos(const std::string& archivo) {
//        std::ifstream file(archivo);
//        if (!file) {
//            std::cout << "Error al abrir el archivo." << std::endl;
//            return;
//        }
//
//        std::string line;
//        std::getline(file, line);  // Leer encabezado
//
//        while (std::getline(file, line)) {
//            std::stringstream ss(line);
//            std::string iso_code, continent, location;
//            int total_cases, total_deaths;
//            double total_cases_per_million, total_deaths_per_million;
//
//            std::getline(ss, iso_code, ',');
//            std::getline(ss, continent, ',');
//            std::getline(ss, location, ',');
//            ss >> total_cases;
//            ss.ignore();
//            ss >> total_deaths;
//            ss.ignore();
//            ss >> total_cases_per_million;
//            ss.ignore();
//            ss >> total_deaths_per_million;
//
//            Registro registro(iso_code, continent, location, total_cases, total_deaths, total_cases_per_million,
//                total_deaths_per_million);
//            registros.push_back(registro);
//        }
//
//        file.close();
//    }
//
//    void indexarPorTotalCases() {
//        for (auto& registro : registros) {
//            arbol_indices[registro.location].push(&registro);
//        }
//    }
//
//    void mostrarCantidadRegistros() {
//        std::cout << "Cantidad de registros: " << registros.size() << std::endl;
//    }
//
//    void mostrarPaisConMasCasos() {
//        int maxCases = 0;
//        std::string paisMasCasos;
//
//        for (const auto& entry : arbol_indices) {
//            if (entry.second.top()->total_cases > maxCases) {
//                maxCases = entry.second.top()->total_cases;
//                paisMasCasos = entry.first;
//            }
//        }
//
//        std::cout << "País con más casos: " << paisMasCasos << std::endl;
//    }
//
//    void mostrarPaisConMenosCasos() {
//        int minCases = std::numeric_limits<int>::max();
//        std::string paisMenosCasos;
//
//        for (const auto& entry : arbol_indices) {
//            if (entry.second.top()->total_cases < minCases) {
//                minCases = entry.second.top()->total_cases;
//                paisMenosCasos = entry.first;
//            }
//        }
//
//        std::cout << "País con menos casos: " << paisMenosCasos << std::endl;
//    }
//
//    void mostrarPaisesMenorCantidadCasosPorMillon() {
//        std::priority_queue<Registro*, std::vector<Registro*>, CompareByTotalCasesPerMillion> colaPrioridad;
//
//        for (const auto& entry : arbol_indices) {
//            colaPrioridad.push(entry.second.top());
//        }
//
//        std::cout << "Países con menor cantidad de casos por millón de habitantes:" << std::endl;
//        for (int i = 0; i < 5; ++i) {
//            std::cout << colaPrioridad.top()->location << std::endl;
//            colaPrioridad.pop();
//        }
//    }
//};
//
//// Clase HashTable
//class HashTable {
//private:
//    std::vector<std::list<Registro>> hash_table;
//    int size;
//
//    // Función de hash
//    size_t hashFunction(const std::string& key) const {
//        size_t hash = 0;
//        for (char ch : key) {
//            hash = hash * 31 + ch;
//        }
//        return hash % size;
//    }
//
//public:
//    HashTable(int size) : size(size) {
//        hash_table.resize(size);
//    }
//
//    void insert(const Registro& registro) {
//        size_t index = hashFunction(registro.location);
//        hash_table[index].push_back(registro);
//    }
//
//    void display() const {
//        for (size_t i = 0; i < size; ++i) {
//            std::cout << "Index " << i << ": ";
//            for (const Registro& registro : hash_table[i]) {
//                std::cout << registro.location << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    Diagnostico diagnostico;
//    diagnostico.cargarDatos("dt_covid.csv");
//    diagnostico.indexarPorTotalCases();
//    diagnostico.mostrarCantidadRegistros();
//    diagnostico.mostrarPaisConMasCasos();
//    diagnostico.mostrarPaisConMenosCasos();
//    diagnostico.mostrarPaisesMenorCantidadCasosPorMillon();
//
//    return 0;
//}
