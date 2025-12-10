#include <iostream>
using namespace std;
struct Node{
    Node* prev;
    int data;
    Node* next;
};
class DoubleLinkedList{
    Node* head;
public:
    DoubleLinkedList() {
        head=NULL;
    }
    bool add_begin(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        newNode->prev =NULL;
        return true;
    }
    bool del_begin(){
         if (head == NULL) {
        return false;  
         }
        Node *temp=head ;
        head = temp->next;
        head->prev =NULL;
        delete temp;
        return true;
    }
    
    bool add_end(int value){
        if(head == NULL){
            return add_begin(value);
        }
        Node* newNode = new Node;
        newNode->data = value;
        Node* temp = head;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next =NULL;
        return true;
    }
    bool del_end(){
        if (head == NULL) {
        return false;  
        }
        Node *temp=head ;
        while (temp->next !=NULL )
        {
            temp = temp->next; 
        }
        if(temp->prev==NULL){
            head = NULL;
            delete temp;
            return true;
        }
        temp->prev->next = temp->next;
        delete temp;
        return true;
    }
    bool add_between_nodes(int value , int pos){
        if(head == NULL || pos<=1){
            return add_begin(value);
        }
        Node* newNode = new Node;
        newNode->data = value;
        Node* temp = head;
        int c = 1;
        while (temp !=NULL && c<pos-1)
        {
            temp = temp->next; 
            c++;
        }
        if(temp==NULL) return false;
        Node* nextNode = temp->next;   
        newNode->next=nextNode;
        temp->next = newNode;
        newNode->prev = temp;
         if (nextNode != NULL) {
        nextNode->prev = newNode;   
    }
        return true;
        
    }
    bool del_between_nodes(int pos){
        if(head == NULL || pos<=1){
            return del_begin();
        }
        Node* temp = head;
        int c = 1;
        while (temp !=NULL && c<pos-1)
        {
            temp = temp->next; 
            c++;
        }
        if(temp == NULL || temp->next == NULL) return false;
        Node* RemoveNode = temp->next;   
        temp->next = RemoveNode->next;
         if (RemoveNode != NULL) {
        RemoveNode->next->prev = temp;   
    }
        delete RemoveNode;
        return true;
        
    }
};