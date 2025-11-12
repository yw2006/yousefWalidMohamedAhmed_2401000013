#include <iostream>
using namespace std;
struct Node
{
    int Data;
    Node* next;
};
class LinkedList{
    Node* head;
    LinkedList(){
        head=NULL;
    }
    bool add_begin(int x){
        Node newNode;
        if(head==NULL){
            head=&newNode;
            newNode.Data=x;
            newNode.next=NULL;
        }else{
            newNode.Data=x;
            newNode.next = head;
            head = &newNode;
        }
    }
    bool add_specific_place(int x){

    }
    bool add_end(int x){
        Node* endEl;
        endEl = head;
        while(endEl!=NULL){
            endEl = endEl->next;
        }
        Node newNode;
        endEl->next = &newNode;
        newNode.next=NULL;
        newNode.Data=x;
    }
};
int main(){

    return 0;
}
