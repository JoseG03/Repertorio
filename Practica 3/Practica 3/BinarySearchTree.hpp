#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <functional>

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree(std::function<void(T)> show, std::function<bool(T, T)> compare, std::function<bool(T, T)> equals) : _show(show), _compare(compare), _equals(equals) {
        _root = nullptr;
        _size = 0ll;
    }
    void insert(T value) {
        _insert(_root, value);
    }
    void preOrder() {
        _preOrder(_root);
    }
    // Rightmost element
    T max() {
        Node* aux = _root;
        while (aux->rightChild != nullptr) aux = aux->rightChild;
        return aux->value;
    }
    // Leftmost element
    T min() {
        Node* aux = _root;
        while (aux->leftChild != nullptr) aux = aux->leftChild;
        return aux->value;
    }
    void roadTree(std::function<void(T)> countInRange) {
        _road(_root, countInRange);
    }
private:
    struct Node {
        T value;
        Node* leftChild;
        Node* rightChild;
    };
    Node* _root;
    size_t _size;
    std::function<void(T)> _show;
    std::function<bool(T, T)> _compare;
    std::function<bool(T, T)> _equals;
private:
    void _insert(Node*& n, T value) {
        if (n == nullptr) {
            n = new Node{ value, nullptr, nullptr };
            return;
        }
        if (_equals(n->value, value)) return;
        if (_compare(n->value, value)) _insert(n->leftChild, value);
        else _insert(n->rightChild, value);
    }
    void _preOrder(Node* n) {
        // if(n == nullptr) return;
        if (!n) return;
        _show(n->value); // N
        _preOrder(n->leftChild); // Izq
        _preOrder(n->rightChild); // Der
    }
    void _road(Node* n, std::function<void(T)> countInRange) {
        if (!n) return;
        countInRange(n->value);
        _road(n->leftChild, countInRange);
        _road(n->rightChild, countInRange);
    }
};

#endif