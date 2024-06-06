#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int diameter(Node* tree) {
    if (tree == nullptr)
        return 0;
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);
    int leftDiameter = diameter(tree->left);
    int rightDiameter = diameter(tree->right);
    return std::max(leftHeight + rightHeight + 1, std::max(leftDiameter, rightDiameter));
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    std::cout << "Diameter of the binary tree is: " << diameter(root) << "\n";
    return 0;
}