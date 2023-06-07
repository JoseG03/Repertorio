#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

Node* findMinNode(Node* root) {
    if (root == nullptr)
        return nullptr;
    else if (root->left == nullptr)
        return root;
    else
        return findMinNode(root->left);
}

Node* findMaxNode(Node* root) {
    if (root == nullptr)
        return nullptr;
    else if (root->right == nullptr)
        return root;
    else
        return findMaxNode(root->right);
}

Node* findNode(Node* root, int value) {
    if (root == nullptr || root->data == value)
        return root;
    else if (value < root->data)
        return findNode(root->left, value);
    else
        return findNode(root->right, value);
}

Node* findSuccessor(Node* root, int value) {
    Node* current = findNode(root, value);

    if (current == nullptr)
        return nullptr;

    // If the node has a right subtree, the successor is the minimum node in the right subtree
    if (current->right != nullptr) {
        return findMinNode(current->right);
    }
    else {
        // Otherwise, the successor is the nearest ancestor whose left child is also an ancestor of the given node
        Node* successor = nullptr;
        Node* ancestor = root;

        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }

        return successor;
    }
}

Node* findPredecessor(Node* root, int value) {
    Node* current = findNode(root, value);

    if (current == nullptr)
        return nullptr;

    // If the node has a left subtree, the predecessor is the maximum node in the left subtree
    if (current->left != nullptr) {
        return findMaxNode(current->left);
    }
    else {
        // Otherwise, the predecessor is the nearest ancestor whose right child is also an ancestor of the given node
        Node* predecessor = nullptr;
        Node* ancestor = root;

        while (ancestor != current) {
            if (current->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else {
                ancestor = ancestor->left;
            }
        }

        return predecessor;
    }
}

int getNodeCountAtLevel(Node* root, int level) {
    if (root == nullptr)
        return 0;

    if (level == 1)
        return 1;

    return getNodeCountAtLevel(root->left, level - 1) + getNodeCountAtLevel(root->right, level - 1);
}

void deleteNode(Node*& root, int value) {
    if (root == nullptr)
        return;

    if (value < root->data) {
        deleteNode(root->left, value);
    }
    else if (value > root->data) {
        deleteNode(root->right, value);
    }
    else {
        // Node found, perform deletion

        // Case 1: No child or a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: One child (left child)
        else if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: One child (right child)
        else if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        // Case 4: Two children
        else {
            Node* successor = findMinNode(root->right);
            root->data = successor->data;
            deleteNode(root->right, successor->data);
        }
    }
}

void printNodesAtLevel(Node* root, int level) {
    if (root == nullptr)
        return;

    if (level == 1) {
        cout << root->data << " ";
    }
    else if (level > 1) {
        printNodesAtLevel(root->left, level - 1);
        printNodesAtLevel(root->right, level - 1);
    }
}

int getTreeHeight(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void printLevelOrder(Node* root) {
    int height = getTreeHeight(root);
    for (int i = 1; i <= height; i++) {
        cout << "Nivel " << i << ": ";
        printNodesAtLevel(root, i);
        cout << endl;
    }
}

int main() {
    int elements[] = { 1, 4, 5, 10, 16, 17, 21 };
    int size = sizeof(elements) / sizeof(elements[0]);

    Node* root = nullptr;

    for (int i = 0; i < size; i++) {
        root = insert(root, elements[i]);
    }

    int option;
    int level;
    int value;

    do {
        system("cls");
        cout << "------------------------" << endl;
        cout << "1. Dibujar arbol de busqueda" << endl;
        cout << "2. Obtener el nodo minimo del arbol" << endl;
        cout << "3. Obtener el nodo maximo del arbol" << endl;
        cout << "4. Obtener el sucesor y predecesor de un nodo" << endl;
        cout << "5. Obtener el numero de nodos por nivel del arbol" << endl;
        cout << "6. Eliminar un nodo del arbol" << endl;
        cout << "7. Salir" << endl;
        cout << "------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option) {
        case 1:
            printLevelOrder(root); system("pause");
            break;
        case 2:
            // Obtener el nodo mínimo del árbol
            cout << "El nodo minimo del arbol es: " << findMinNode(root)->data << endl;
            system("pause");
            break;
        case 3:
            // Obtener el nodo máximo del árbol
            cout << "El nodo maximo del arbol es: " << findMaxNode(root)->data << endl;
            system("pause");
            break;
        case 4:
            // Obtener el sucesor y predecesor de un nodo
            printLevelOrder(root);
            cout << "Ingrese el valor del nodo: ";
            cin >> value;
            {
                Node* node = findNode(root, value);
                if (node == nullptr) {
                    cout << "El nodo no existe en el arbol." << endl;
                }
                else {
                    Node* successor = findSuccessor(root, value);
                    Node* predecessor = findPredecessor(root, value);
                    cout << "El sucesor de " << value << " es: ";
                    if (successor != nullptr)
                        cout << successor->data << endl;
                    else
                        cout << "No tiene sucesor." << endl;

                    cout << "El predecesor de " << value << " es: ";
                    if (predecessor != nullptr)
                        cout << predecessor->data << endl;
                    else
                        cout << "No tiene predecesor." << endl;
                }
            }
            system("pause");
            break;
        case 5:
            // Obtener el número de nodos por nivel del árbol
            cout << "Numero de nodos por nivel:" << endl;
            for (int i = 1; i <= 6; i++) {
                cout << "Nivel " << i << ": " << getNodeCountAtLevel(root, i) << " nodos" << endl;
            }
            system("pause");
            break;
        case 6:
            // Eliminar un nodo del árbol
            printLevelOrder(root);
            cout << "Ingrese el valor del nodo a eliminar: ";
            cin >> value;
            deleteNode(root, value);
            cout << "Nodo eliminado exitosamente." << endl;
            system("pause");
            break;
        case 7:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;

        }

        cout << endl;

    } while (option != 7);

    return 0;
}
