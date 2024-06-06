node* mergeTwoLists(node* l1, node* l2) {
#include "../../../../../../TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/10.3.0/include/c++/bits/node_handle.h"
#include <node.h>
#include <iostream>

node* mergeTwoLists(node* l1, node* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    
    node* head = nullptr;
    node* tail = nullptr;
    
    if (l1->data <= l2->data) {
        head = l1;
        tail = l1;
        l1 = l1->next;
    } else {
        head = l2;
        tail = l2;
        l2 = l2->next;
    }
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    
    if (l1 != nullptr) {
        tail->next = l1;
    }
    if (l2 != nullptr) {
        tail->next = l2;
    }
    
    return head;
}