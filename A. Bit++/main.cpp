#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
    cin >> n;
	int x = 0;
	while (n--) {
		string w;
		if (!(cin >> w)) return 0;
		if (w == "X++" || w == "++X") {
			x++;
		}
		else if (w == "X--" || w == "--X") {
			x--;
		}
	}
	cout << x << endl;
	return 0;
}