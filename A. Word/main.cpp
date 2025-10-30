#include <iostream>
using namespace std;
string textLower(string s){
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}
string textUpper(string s){
    for (char &c : s) {
        c = toupper(c);
    }
    return s;
}
int main()
{
    string w;
    cin >> w;
    int cap=0,sml=0;
    for(int i =0 ; i < w.size();i++){
        if(w[i]>=65 && w[i]<=90){
            cap++;
        }else{
            sml++;
        }
    };
    if(cap>sml){
        cout << textUpper(w);
    }else{
        cout << textLower(w);
        
    }
    return 0;
}

