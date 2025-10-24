#include <iostream>
using namespace std;
class MinStack {
   
public:
    int* arr;
    int topIndex;
    int capacity;
    int minValue;
    MinStack() {
        capacity=20;
        arr = new int[capacity];
        topIndex=-1;
        minValue = INT_MAX;
    }
    ~MinStack(){delete[] arr;}
    void resize(){
        int newCapacity = capacity*2;
        int* newData = new int[newCapacity];
        for(int i = 0;i<capacity;i++){
            newData[i]=arr[i];
        }
        delete[] arr;
        arr = newData;
        capacity = newCapacity;

    }
    void push(int val) {
        if(capacity == topIndex+1){
            resize();
        }
        if(topIndex==-1 || minValue > val){
            minValue=val;
        }
        arr[++topIndex]=val;
    }
    
    void pop() {
        if(topIndex<0){
            return;
        }
        int popped = top();
        topIndex--;
        if(popped == minValue && topIndex>=0){
            minValue=arr[0];
        for(int i;i<=topIndex;i++){
           if(minValue > arr[i]){
            minValue=arr[i];
           }
        }
        }else if (topIndex < 0){
            minValue=INT_MAX;
        }
    }
    
    int top() {
         return arr[topIndex];
         
    }
    
    int getMin() {
        return minValue;
    }
};
