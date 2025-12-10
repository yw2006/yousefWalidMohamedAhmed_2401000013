#include <iostream>
using namespace std;
struct Node
{
    int Data;
    Node* next;
};
class LinkedList{
public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    bool add_begin(int x) {
        Node* newNode = new Node;
        newNode->Data = x;
        newNode->next = head;
        head = newNode;
        return true;
    }
    bool add_specific_place(int value,int position){
          Node* x = head;
          Node* newNode = new Node;
          newNode->Data=value;
          int c = 1;
          while (x->next !=NULL && position-1!=c)
          {
            x = x->next;
            c++;
          }
        newNode->next = x->next;
        x->next = newNode;
        return true;
    }
// add with search about value 
    bool add_after_specific_place(int value,int search){
        Node* x = head;
        Node* newNode = new Node;
        newNode->Data=value;
        while (x->next !=NULL && x->Data !=search)
        {
            x = x->next;
        }
        newNode->next = x->next;
        x->next = newNode;
        return true;    
    }
    bool add_end(int x){
        Node* endEl;
        endEl = head;
        while(endEl->next!=NULL){
            endEl = endEl->next;
        }
        Node* newNode = new Node;
        endEl->next = newNode;
        newNode->next=NULL;
        newNode->Data=x;
        return true;
    }
    void PrintList()
        {
        Node* node = head;
        while (node != NULL){
        cout << node->Data << "->";
        node = node->next;
        }
    }
    void delete_begin(){
            Node* temp = head;
            head=head->next;
            delete temp;
    }
    void delete_specific_place(int pos){
        Node* temp = head;
        int c = 1;
        while(temp->next!=NULL && c !=pos-1){
            temp=temp->next;
            c++;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;

    }
   void delete_after_specific_place(int search) {
    Node* temp = head;

    while (temp != NULL && temp->Data != search) {
        temp = temp->next;
    }

    if (temp == NULL) return; 

    if (temp->next == NULL) return; 

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}
void delete_end() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;

    temp->next = NULL;   
    delete nodeToDelete; 
}
int count_nodes(){
    Node* temp = head;
    int c = 1;
    while(temp->next!=NULL){
        c++;
    }
    return c;
}

};
int main(){
    LinkedList l1;
    l1.add_begin(10);
    l1.add_begin(20);
    l1.add_specific_place(50,2);
    l1.add_after_specific_place(30,20);
    l1.delete_specific_place(2);
    l1.delete_after_specific_place(10);
    l1.add_end(100);
    l1.PrintList();
    l1.count_nodes();
    return 0;
}
