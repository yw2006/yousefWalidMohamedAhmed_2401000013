#include <iostream>
#include <string>
using namespace std;
class Stack{
    string arr[50];
    int top;
public:
    Stack(){
        top=-1;
    }
    

    string pop(){
        if(isEmpty()){
            return "";
        }
        return arr[top--];
    }
    
    bool push(string value){
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
        return top>=50;
    }
    
    bool peek(){
        if(isEmpty()){
            return false;
        }
        cout << arr[top]<<endl;
        return true;
    }
    
};
void addText(string& text){
    cout << "Enter text to add: ";
    string w ;
    cin >> w;
    text +=w; 
}
void deleteChar(string& text){
    cout << "How many characters to delete: ";
    int n;
    cin >> n;
    text.erase(text.length()-n,text.length()-1);

}
int main() {
    Stack undo;
    Stack redo;
    string text="";
    cout << "1. Add text" << endl<<  "2. Delete characters" << endl<< "3. Undo" << endl << "4. Redo" << endl << "5. Show current text" << endl << "6. Exit" << endl;
    int inp;
    do{
        cout << "Choose option: " << endl;
        cin >> inp;
        switch (inp){
    case 1:
        undo.push(text);
        addText(text);
        break;
    case 2:
        undo.push(text);
        deleteChar(text);
        break;
    case 3:
        redo.push(text);
        text = undo.pop();
        cout << "Undo done.";
        cout << "Current text: "<< text << endl;
        break;
    case 4:
        undo.push(text);
        text = redo.pop();
        cout << "Redo done.";
        cout << "Current text: "<< text << endl;
        break;
    case 5:
        cout << "Current text: "<< text << endl;
        break;
    default:
        cout << "bye";
        return 0;
     }}
    while (true);
    
    
    
}