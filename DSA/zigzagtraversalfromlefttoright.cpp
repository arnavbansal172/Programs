#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* left;
    Node* right;
};

void printLeftToRight(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> stack1;
    std::stack<Node*> stack2;

    stack1.push(root);

    while (!stack1.empty() || !stack2.empty()) {
        while (!stack1.empty()) {
            Node* current = stack1.top();
            stack1.pop();
            std::cout << current->data << " ";

            if (current->left) {
                stack2.push(current->left);
            }
            if (current->right) {
                stack2.push(current->right);
            }
        }

        while (!stack2.empty()) {
            Node* current = stack2.top();
            stack2.pop();
            std::cout << current->data << " ";

            if (current->right) {
                stack1.push(current->right);
            }
            if (current->left) {
                stack1.push(current->left);
            }
        }
    }
}

int main() {
    // Create a binary tree
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 7;

    // Print the output from left to right
    printLeftToRight(root);

    return 0;
}