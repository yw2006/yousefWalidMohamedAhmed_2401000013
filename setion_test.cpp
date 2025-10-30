#include <iostream>
using namespace std;
#define size 10
class Queue{
int arr[size];
int rear , front ;
public:
Queue(){
rear = 0;
front = -1;
}
bool isFull(){
if(rear==size){
    return true;
}
return false;
}
bool isEmpty(){
if(rear==0 && front==-1){
    return true;
}
return false;
}
bool enqueue(int value){
    if(isFull()){
        return false;
    }
    if(isEmpty()){
        front++;
    }
    arr[rear++]=value;
    return true;
}
int dequeue(){
    if(isEmpty()){
        return -1;
    }
    return arr[front++];
}
};
int main(){

}
