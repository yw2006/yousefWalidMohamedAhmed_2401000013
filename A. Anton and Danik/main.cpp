#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string w;
    cin >> w;
    int aCount= 0,dCount =0;
    for (int i = 0; i < n; i++)
    {
        if(w[i]=='D'){
            dCount++;
        }else{
            aCount++;
        }
    }
    if(aCount>dCount){
        cout << "Anton";
    }else if (aCount<dCount)
    {
        cout << "Danik";
    }else{
        cout << "Friendship";
    }
    
}