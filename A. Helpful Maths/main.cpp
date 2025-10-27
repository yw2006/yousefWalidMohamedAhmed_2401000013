#include <iostream>
using namespace std;
int main() {
    string w;
    cin >> w;
    for(int i=1;i<w.size();i++){
        for(int j=i;j<w.size();j++){
            if (w[j]=='+' && w[i-1]>w[j+1]){
            char temp = w[j+1];
            w[j+1]=w[i-1];
            w[i-1]=temp;
        }
        }
    }
    cout << w;
    return 0;
}