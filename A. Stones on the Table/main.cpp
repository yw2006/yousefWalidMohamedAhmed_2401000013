#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string values;
    cin >> values;
    int numNeighbors=0;
    for(int i = 0; i < n-1; i++){
        if(values[i]==values[i+1]){
            numNeighbors++;
        }
    }
    cout << numNeighbors;
    
}