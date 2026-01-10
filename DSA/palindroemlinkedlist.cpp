#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    stack<int> st;

    while (fast != nullptr && fast->next != nullptr) {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the linked list has odd number of nodes, skip the middle node
    if (fast != nullptr) {
        slow = slow->next;
    }

    while (slow != nullptr) {
        if (slow->val != st.top()) {
            return false;
        }
        st.pop();
        slow = slow->next;
    }

    return true;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Clean up memory
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}