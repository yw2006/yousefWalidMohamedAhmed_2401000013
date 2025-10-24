#include <iostream>
using namespace std;
class Stack{
    int* arr;
    int top;
    int capacity;
public:
    Stack(){
        top=-1;
        capacity=5;
        arr = new int[capacity];
    }
    
    Stack(int size){
        top=-1;
        capacity=size ;
        arr = new int[capacity];
    }
    
    ~Stack(){ delete[] arr; }
    
    int pop(){
        if(isEmpty()){
            return -1;
        }
        return arr[top--];
    }
    
    bool push(int value){
        if(isFull()){
            return false;
        }
        arr[++top]=value;
        return true;
    }
    
    bool isEmpty(){
        return top<0;
    }
    
    bool isFull(){
        return top>=capacity-1;
    }
    
    bool peek(){
        if(isEmpty()){
            return false;
        }
        cout << arr[top]<<endl;
        return true;
    }
    
};
int main() {
    Stack s(3);
    if (!s.push(10)){
        cout << "when push 10 the stack is full"<< endl;
    }
    if (!s.push(20)){
        cout << "when push 20 the stack is full"<< endl;
    }
    if (!s.push(30)){
        cout << "when push 30 the stack is full"<< endl;
    }
    if (!s.push(40)){
        cout << "when push 40 the stack is full"<< endl;
    }
    if(!s.peek()){
        cout << "the stack is empty"<< endl;
    }
    if(s.pop()!=-1){
        cout << "the poped value " << s.pop() << endl;
    }else{
        cout << "the stack is empty"<< endl;
    }
    
}