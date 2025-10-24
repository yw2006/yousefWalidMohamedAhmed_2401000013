#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    if(!(cin >> n)) return 0;
    while(n--){
    string w;
    cin >> w;
    int wordLength = w.length();
    if(wordLength>10){
        cout << w[0] << wordLength-2 << w[wordLength-1] << endl;
    }else{
        cout << w << endl;
    }
    }
    return 0;
}