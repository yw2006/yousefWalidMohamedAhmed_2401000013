#include <iostream>
using namespace std;
int main(){
    string w1,w2;
    cin >> w1;
    cin >> w2;
    if(w1.size()!=w2.size()){
        cout << "NO" << endl;
    }else{
    int wSize= w1.size();
    for (size_t i = 0; i <wSize ; i++)
    {
        if(w1[i]!=w2[wSize-1-i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    }
    return 0;    
}