#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class circularLinkedList{
    Node* tail;
public:
    circularLinkedList(){
        tail = NULL;
    }
    bool add_begin(int value){
        Node* newNode= new Node;
        newNode->data = value;
        if(tail==NULL){
        newNode->next = newNode;
        tail = newNode;
        return true;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        return true;
    }
    bool add_end(int value){
        Node* newNode= new Node;
        newNode->data = value;
        if(tail==NULL){
        return add_begin(value);
        }
        newNode->next = tail->next;
        tail->next =  newNode;
        tail = newNode;
        return true;
    }
    bool add_between_nodes(int value,int pos){
        if(tail == NULL || pos <=1){
            return add_begin(value);
        }
        Node* newNode= new Node;
        newNode->data = value;
        Node* temp=tail;
        int c=1;
        while(temp->next != tail && c!= pos-1 ){
            temp=temp->next;
            c++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
        return true;
    }
   void printList() {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);

    cout << endl;
}

    
};
class CircularLinkedList{
    Node* head;
    Node* tail;
    CircularLinkedList(){
        head = NULL;
        tail = NULL;
    }
    bool add_begin(int value){
        Node* newNode = new Node;
        newNode->data = value;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;  
            return true;
        }
        newNode->next = head;
        head = newNode;
        tail = head;
        return true;
    }
    bool add_end(int value) {
        if (head == NULL) { 
            return add_begin(value);
        }
        Node* newNode = new Node;
        newNode->data = value;
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
        return true;
    }
    bool del_begin() {
        if (head == NULL) return false;

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete temp;
        return true;
    }

    bool del_end() {
        if (head == NULL) return false;
        if (head == tail) {
            return del_begin();
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = head;
        delete tail;
        tail = temp;
        return true;
    }
    bool add_between_nodes(int value, int pos) {
        if (pos <= 1) return add_begin(value);

        Node* temp = head;
        int c = 1;

        while (c < pos - 1 && temp->next != head) {
            temp = temp->next;
            c++;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) tail = newNode;

        return true;
    }

    bool del_between_nodes(int pos) {
        if (head == NULL || pos <= 1) return del_begin();

        Node* temp = head;
        int c = 1;

        while (c < pos - 1 && temp->next != head) {
            temp = temp->next;
            c++;
        }

        Node* RemoveNode = temp->next;
        if (RemoveNode == head) return false;

        temp->next = RemoveNode->next;

        if (RemoveNode == tail) tail = temp;

        delete RemoveNode;
        return true;
    }

};
int main(){
    circularLinkedList cl;
    cout << cl.add_begin(10)<<endl ; 
    cout << cl.add_begin(20)<<endl ; 
    cout << cl.add_begin(30)<<endl ; 
    cl.printList();
}