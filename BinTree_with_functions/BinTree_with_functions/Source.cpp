#include <iostream>
#include<Windows.h>
using namespace std;

// Вузол бінарного дерева
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Клас бінарного дерева
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Додавання вузла
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Пошук вузла
    bool search(int value) {
        return searchRec(root, value);
    }

    // Визначення глибини вузла
    int getDepth(Node* node, int value, int depth = 0) {
        if (node == nullptr) return -1;
        if (node->data == value) return depth;
        int level = getDepth(node->left, value, depth + 1);
        if (level != -1) return level;
        return getDepth(node->right, value, depth + 1);
    }

    // Визначення висоти дерева
    int getHeight(Node* node) {
        if (node == nullptr) return -1;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Виведення дерева (обхід в порядку зростання)
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

private:
    // Рекурсивне додавання вузла
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    // Рекурсивний пошук вузла
    bool searchRec(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return searchRec(node->left, value);
        }
        return searchRec(node->right, value);
    }

    // Рекурсивний обхід в порядку зростання
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "Меню:\n";
        cout << "1. Додати елемент до дерева\n";
        cout << "2. Пошук даних у дереві\n";
        cout << "3. Визначення глибини вузла\n";
        cout << "4. Визначення висоти дерева\n";
        cout << "5. Обхід дерева\n";
        cout << "6. Вихід\n";
        cout << "Введіть ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть значення для додавання: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Введіть значення для пошуку: ";
            cin >> value;
            if (tree.search(value)) {
                cout << "Значення " << value << " знайдено у дереві.\n";
            }
            else {
                cout << "Значення " << value << " не знайдено у дереві.\n";
            }
            break;
        case 3:
            cout << "Введіть значення для визначення глибини: ";
            cin >> value;
            int depth;
            depth = tree.getDepth(tree.root, value);
            if (depth != -1) {
                cout << "Глибина вузла зі значенням " << value << ": " << depth << endl;
            }
            else {
                cout << "Значення " << value << " не знайдено у дереві.\n";
            }
            break;
        case 4:
            cout << "Висота дерева: " << tree.getHeight(tree.root) << endl;
            break;
        case 5:
            cout << "Обхід дерева в порядку зростання: ";
            tree.inorder();
            break;
        case 6:
            cout << "Вихід.\n";
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
