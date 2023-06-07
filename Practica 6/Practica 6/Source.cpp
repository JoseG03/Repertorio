#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Función para validar la entrada de enteros
int getValidIntegerInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                // La entrada es válida
                break;
            }
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Entrada invalida. Intentelo de nuevo." << std::endl;
    }
    return value;
}

// Función para crear un arreglo
std::vector<int> createArray() {
    int size = getValidIntegerInput("Ingrese la cantidad de valores para el arreglo: ", 1, std::numeric_limits<int>::max());
    std::vector<int> arr;
    arr.reserve(size);
    for (int i = 0; i < size; ++i) {
        arr.push_back(getValidIntegerInput("Ingrese un valor entero para el arreglo: ", std::numeric_limits<int>::min(), std::numeric_limits<int>::max()));
    }
    return arr;
}

// Función para desordenar un arreglo
void shuffleArray(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(arr.begin(), arr.end(), generator);
}

// Función para imprimir un arreglo
void printArray(const std::vector<int>& arr) {
    for (const auto& value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// Función para ordenar un arreglo usando Heap Sort
void heapSort(std::vector<int>& arr) {
    std::make_heap(arr.begin(), arr.end());
    std::sort_heap(arr.begin(), arr.end());
}

// Función para realizar el ordenamiento con tablas de hash
void hashTableSort() {
    std::vector<std::string> arr;
    int size = getValidIntegerInput("Ingrese la cantidad de valores para el arreglo: ", 1, std::numeric_limits<int>::max());
    arr.reserve(size);
    for (int i = 0; i < size; ++i) {
        std::string value;
        std::cout << "Ingrese un valor para el arreglo: ";
        std::cin >> value;
        arr.push_back(value);
    }

    std::cout << "Elementos del arreglo y su valor de hash:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::hash<std::string> hasher;
        size_t hashValue = hasher(arr[i]);
        std::cout << i + 1 << ") " << arr[i] << " tiene un valor de hash -> " << hashValue << std::endl;
    }
}

// Función para realizar la búsqueda binaria en un arreglo
void binarySearch(const std::vector<int>& arr, int value) {
    int low = 0;
    int high = arr.size() - 1;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            index = mid;
            break;
        }
        else if (arr[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (index != -1) {
        std::cout << "El elemento " << value << " se encuentra en el indice " << index << " del arreglo." << std::endl;
    }
    else {
        std::cout << "El elemento " << value << " no se encuentra en el arreglo." << std::endl;
    }
}

// Función para crear un árbol binario con los valores del arreglo
TreeNode* createBinaryTree(const std::vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = createBinaryTree(arr, start, mid - 1);
    root->right = createBinaryTree(arr, mid + 1, end);

    return root;
}

// Función para buscar un elemento en un árbol binario
bool searchInBinaryTree(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    }
    else if (value < root->data) {
        return searchInBinaryTree(root->left, value);
    }
    else {
        return searchInBinaryTree(root->right, value);
    }
}

// Función para imprimir un árbol binario en orden ascendente (inorder traversal)
void printBinaryTreeInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printBinaryTreeInOrder(root->left);
    std::cout << root->data << " ";
    printBinaryTreeInOrder(root->right);
}

// Función principal del programa
int main() {
    std::vector<int> arr;
    TreeNode* root = nullptr;
    bool exitProgram = false;

    while (!exitProgram) {
        system("cls");
        std::cout << "------------------------" << std::endl;
        std::cout << "1. Crear Arreglo" << std::endl;
        std::cout << "2. Desordenar el arreglo" << std::endl;
        std::cout << "3. Ordenar Heap y Heap Sort" << std::endl;
        std::cout << "4. Ordenamiento Tablas Hash" << std::endl;
        std::cout << "5. Búsqueda binaria" << std::endl;
        std::cout << "6. Arboles binarios" << std::endl;
        std::cout << "7. Arboles binarios de busqueda" << std::endl;
        std::cout << "8. Salir" << std::endl;
        std::cout << "------------------------" << std::endl;
        int option = getValidIntegerInput("Ingrese una opcion: ", 1, 8);

        switch (option) {
        case 1:
            arr.clear();
            arr = createArray();
            root = createBinaryTree(arr, 0, arr.size() - 1);
            system("pause");
            break;
        case 2:
            shuffleArray(arr);
            std::cout << "Arreglo desordenado: ";
            printArray(arr);
            system("pause");
            break;
        case 3:
            std::cout << "Arreglo ordenado con Heap: ";
            std::make_heap(arr.begin(), arr.end());
            printArray(arr);
            shuffleArray(arr);
            std::cout << "Arreglo desordenado: ";
            printArray(arr);
            heapSort(arr);
            std::cout << "Arreglo ordenado con Heap Sort: ";
            printArray(arr);
            system("pause");
            break;
        case 4:
            hashTableSort();
            system("pause");
            break;
        case 5:
            if (arr.empty()) {
                std::cout << "El arreglo esta vacio. Primero cree un arreglo." << std::endl;
            }
            else {
                int value = getValidIntegerInput("Ingrese un valor a buscar en el arreglo: ", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                binarySearch(arr, value);
            }
            system("pause");
            break;
        case 6:
            if (arr.empty()) {
                std::cout << "El arreglo esta vacio. Primero cree un arreglo." << std::endl;
            }
            else {
                std::cout << "Arbol binario creado con los valores del arreglo: ";
                printBinaryTreeInOrder(root);
                std::cout << std::endl;
            }
            system("pause");
            break;
        case 7:
            if (root == nullptr) {
                std::cout << "El arbol binario esta vacio. Primero cree un arbol." << std::endl;
            }
            else {
                int value = getValidIntegerInput("Ingrese un valor a buscar en el arbol binario: ", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                bool found = searchInBinaryTree(root, value);
                if (found) {
                    std::cout << "El valor " << value << " se encuentra en el arbol binario." << std::endl;
                }
                else {
                    std::cout << "El valor " << value << " no se encuentra en el arbol binario." << std::endl;
                }
            }
            system("pause");
            break;
        case 8:
            exitProgram = true;
            break;
        default:
            std::cout << "Opcion invalida. Intentelo de nuevo." << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}
