#include <iostream>
using namespace std;
int main() {
	int n,k;
    cin >> n >> k;
    int* values=new int[n];
    int result=0;
    for(int i = 0;i<n;i++){
        cin >> values[i];
    }
    int kth_value=values[k-1];
    for(int i = 0;i<n;i++){
        if(values[i] >= kth_value && values[i] > 0){
            result++;
        }
    }
    cout << result << endl ;
}