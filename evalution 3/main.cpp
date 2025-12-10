// 1. You have the linked list: 5 → 10 → 15 → 20 → NULL.
// What will the list look like after deleting the node containing 15?
// A) 5 → 10 → 20

// 2. Which operation can be performed in O(1) on a singly linked list?
// A) Insert a node at the beginning
#include <iostream>
using namespace std;

// Count Nodes
int count_nodes(){
    Node* temp = head;
    int c = 1;
    while(temp->next!=NULL){
        c++;
    }
    return c;
}

// Debugging – Delete Node
// the crashes happend because this access the last node and delete the next and this make error 
void delete_after_specific_place(int search) {
    Node* temp = head;

    while (temp != NULL && temp->Data != search) {
        temp = temp->next;
    }

    if (temp == NULL) return; 

    if (temp->next == NULL) return; 

    Node* nodeDelete = temp->next;
    temp->next = nodeDelete->next;

    delete nodeDelete;
} 
