#include <iostream>
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

    // Видалення вузла
    void remove(int value) {
        root = removeRec(root, value);
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
        } else if (value > node->data) {
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

    // Рекурсивне видалення вузла
    Node* removeRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = removeRec(node->left, value);
        } else if (value > node->data) {
            node->right = removeRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    // Пошук вузла з мінімальним значенням
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
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
    BinaryTree tree;

    // Додавання елементів
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Виведення дерева
    cout << "Inorder traversal: ";
    tree.inorder();

    // Пошук елементів
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    // Видалення елементів
    tree.remove(20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder();

    tree.remove(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder();

    tree.remove(50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder();

    return 0;
}
