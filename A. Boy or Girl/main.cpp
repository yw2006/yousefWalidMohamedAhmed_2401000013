#include <iostream>
#include <set>
using namespace std;
int main() {
    string w;
    cin >> w;
    set<char> values;
    for(char c:w){
        values.insert(c);
    }
    if (values.size()%2==0){
        cout << "CHAT WITH HER!" ;
    }else{
        cout << "IGNORE HIM!" ;
    }
    return 0;
}