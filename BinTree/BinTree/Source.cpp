#include <iostream>
using namespace std;

// ����� �������� ������
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// ���� �������� ������
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // ��������� �����
    void insert(int value) {
        root = insertRec(root, value);
    }

    // ����� �����
    bool search(int value) {
        return searchRec(root, value);
    }

    // ��������� �����
    void remove(int value) {
        root = removeRec(root, value);
    }

    // ��������� ������ (����� � ������� ���������)
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

private:
    // ���������� ��������� �����
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

    // ����������� ����� �����
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

    // ���������� ��������� �����
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

    // ����� ����� � ��������� ���������
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // ����������� ����� � ������� ���������
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

    // ��������� ��������
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // ��������� ������
    cout << "Inorder traversal: ";
    tree.inorder();

    // ����� ��������
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    // ��������� ��������
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
