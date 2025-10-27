#include <iostream>
using namespace std;
int main(){
    int bananaPrice , ownDollars ,numBanana;
    cin >>  bananaPrice >> ownDollars >> numBanana;
    int result = 0;
    for (size_t i = 0; i < numBanana; i++)
    {
       result+= (i+1)*bananaPrice;
    }
    cout << ((result - ownDollars>0)?result - ownDollars:0 ) << endl;
    
}