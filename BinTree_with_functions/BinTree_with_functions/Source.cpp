#include <iostream>
#include<Windows.h>
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

    // ���������� ������� �����
    int getDepth(Node* node, int value, int depth = 0) {
        if (node == nullptr) return -1;
        if (node->data == value) return depth;
        int level = getDepth(node->left, value, depth + 1);
        if (level != -1) return level;
        return getDepth(node->right, value, depth + 1);
    }

    // ���������� ������ ������
    int getHeight(Node* node) {
        if (node == nullptr) return -1;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
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
        }
        else if (value > node->data) {
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "����:\n";
        cout << "1. ������ ������� �� ������\n";
        cout << "2. ����� ����� � �����\n";
        cout << "3. ���������� ������� �����\n";
        cout << "4. ���������� ������ ������\n";
        cout << "5. ����� ������\n";
        cout << "6. �����\n";
        cout << "������ ��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ �������� ��� ���������: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "������ �������� ��� ������: ";
            cin >> value;
            if (tree.search(value)) {
                cout << "�������� " << value << " �������� � �����.\n";
            }
            else {
                cout << "�������� " << value << " �� �������� � �����.\n";
            }
            break;
        case 3:
            cout << "������ �������� ��� ���������� �������: ";
            cin >> value;
            int depth;
            depth = tree.getDepth(tree.root, value);
            if (depth != -1) {
                cout << "������� ����� � ��������� " << value << ": " << depth << endl;
            }
            else {
                cout << "�������� " << value << " �� �������� � �����.\n";
            }
            break;
        case 4:
            cout << "������ ������: " << tree.getHeight(tree.root) << endl;
            break;
        case 5:
            cout << "����� ������ � ������� ���������: ";
            tree.inorder();
            break;
        case 6:
            cout << "�����.\n";
            return 0;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    }

    return 0;
}
