#include <iostream>
using namespace std;
class Queue{
 int arr[10];
 int head;
 int tail;
public:
 Queue(){
    head=0;
    tail=0;
 }

bool enqueue(int v){
if(isFull()){
    return false;
}

arr[tail++]=v;
return true;
}

int dequeue(){
if(isEmpty()){
    return -1;
}
return arr[head++];
}

int top(){
   if(isEmpty()){
    return -1;
}
return arr[head]; 
}

bool isEmpty(){
if(head!=tail){
return false;
}
return true;
}

bool isFull(){
if(tail>=10){
return true;
}
return false;
}

};
int main(){
    Queue q;
    q.enqueue(10);
    cout << q.dequeue();
    cout << q.dequeue();


}