#include <iostream>
#include <string>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack() {
        top = -1;
        capacity = 5;
        arr = new int[capacity];
    }

    Stack(int size) {
        top = -1;
        capacity = size;
        arr = new int[capacity];
    }

    ~Stack() { delete[] arr; }

    int pop() {
        if (isEmpty()) return -1;
        return arr[top--];
    }

    bool push(int value) {
        if (isFull()) return false;
        arr[++top] = value;
        return true;
    }

    bool isEmpty() { return top < 0; }

    bool isFull() { return top >= capacity - 1; }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    int prority(char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }
    string infixToPostfix(string value) {
        string postfix = "";
        Stack s(value.length());

        for (char ch : value) {
            if (isdigit(ch)) {
                postfix += ch;
                postfix += ' ';
            }
            else if (ch == '(') {
                s.push(ch);
            }
            else if (ch == ')') {
                while (!s.isEmpty() && (char)s.peek() != '(') {
                    postfix += (char)s.pop();
                    postfix += ' ';
                }
                s.pop(); 
            }
            else { 
                while (!s.isEmpty() && prority((char)s.peek()) >= prority(ch)) {
                    postfix += (char)s.pop();
                    postfix += ' ';
                }
                s.push(ch);
            }
        }

        while (!s.isEmpty()) {
            postfix += (char)s.pop();
            postfix += ' ';
        }

        return postfix;
    }

    int evaluatePostfix(string value) {
        Stack s(value.length());
        for (char ch : value) {
            if (isdigit(ch)) {
                s.push(ch - '0');
            }
            else if (ch == ' ') {
                continue;
            }
            else {
                int val2 = s.pop();
                int val1 = s.pop();
                switch (ch) {
                    case '+': s.push(val1 + val2); break;
                    case '-': s.push(val1 - val2); break;
                    case '*': s.push(val1 * val2); break;
                    case '/': s.push(val1 / val2); break;
                }
            }
        }
        return s.pop();
    }
};

int main() {
    Stack s(3);

    // Stack test
    if (!s.push(10)) cout << "Stack full\n";
    if (!s.push(20)) cout << "Stack full\n";
    if (!s.push(30)) cout << "Stack full\n";
    if (!s.push(40)) cout << "Stack full\n";

    if (s.peek() != -1)
        cout << "Top value: " << s.peek() << endl;
    else
        cout << "Stack is empty\n";

    if (s.pop() != -1)
        cout << "Popped value: " << s.pop() << endl;
    else
        cout << "Stack is empty\n";
// example :3+5*2/(1+1)
    string infix;
    cin >> infix;
    string postfix = s.infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = s.evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
