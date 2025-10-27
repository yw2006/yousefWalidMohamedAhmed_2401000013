#include <iostream>
using namespace std;
int main(){
    int w;
    if (!(cin >> w)) return 0 ;
    cout << ((w%2==0 && w>2)?"YES":"NO") << endl;
    return 0;
}