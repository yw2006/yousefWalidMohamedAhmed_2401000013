#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int accpetedIdeas = 0;
    constexpr int inputNumbers = 3;
    for (int i = 0; i < n; i++)
    {
        int accpetedMembers = 0;
        int numbers[inputNumbers];
        for (int j = 0; j < inputNumbers; ++j) {
            cin >> numbers[j];
            if (numbers[j] == 1) {
                accpetedMembers++;
            }

        }
        if (accpetedMembers >= 2) {
            accpetedIdeas++;
        }
    }
    cout << accpetedIdeas;
    return 0;
}