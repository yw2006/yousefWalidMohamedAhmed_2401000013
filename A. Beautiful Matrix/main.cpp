#include <iostream>
using namespace std;
int main() {
    int values[5][5];
    int oneRow,oneColumn;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> values[i][j];
            if(values[i][j]==1){
                oneRow=i+1;
                oneColumn =j+1;
            }
    }
    }
    
    cout <<  abs(oneRow-3)+abs(oneColumn-3) << endl;
}