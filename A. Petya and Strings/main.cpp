#include <iostream>
using namespace std;
string textLower(string s){
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}
int main() {
    string fw,sw;
    cin >> fw >> sw ;
    if(textLower(fw)==textLower(sw)){
        cout << 0;
    }else if (textLower(fw)<textLower(sw)){
        cout << -1;
    }else{
        cout << 1;
    }
    
}