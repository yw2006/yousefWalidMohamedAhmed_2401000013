#include <iostream>
using namespace std;

class MinStack {
public:
    int* arr;
    int topIndex;
    int capacity;
    int minValue;

    MinStack() {
        capacity = 20;
        arr = new int[capacity];
        topIndex = -1;
        minValue = INT_MAX;
    }

    ~MinStack() {
        delete[] arr;
    }

    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < capacity; i++) {
            newData[i] = arr[i];
        }
        delete[] arr;
        arr = newData;
        capacity = newCapacity;
    }

    void push(int val) {
        if (topIndex + 1 == capacity) {
            resize();
        }
        if (topIndex == -1 || val < minValue) {
            minValue = val;
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (topIndex < 0) {
            cout << "Stack is empty!\n";
            return;
        }

        int popped = arr[topIndex];
        topIndex--;

        if (topIndex < 0) {
            minValue = INT_MAX;
            return;
        }

        if (popped == minValue) {
            minValue = arr[0];
            for (int i = 1; i <= topIndex; i++) {
                if (arr[i] < minValue) {
                    minValue = arr[i];
                }
            }
        }
    }

    int top() {
        if (topIndex < 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    int getMin() {
        if (topIndex < 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minValue;
    }
};