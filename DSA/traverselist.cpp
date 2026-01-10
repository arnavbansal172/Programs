#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to traverse the linked list
void traverseList(Node* head) {
    Node* current = head;
    
    while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
    }
}