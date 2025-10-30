#include <iostream>
using namespace std;
int main(){
    string num;
    cin >> num;
    int countofnumbers=0;
    for (int i = 0; i < num.size(); i++)
    { 
        if(num[i]=='7' || num[i]=='4' )
        {
            countofnumbers++;
        }
    }
    if(countofnumbers==7 || countofnumbers==4){
        cout << "YES" << endl;
        return 0;

    }
        cout << "NO" << endl;
        return 0;

}