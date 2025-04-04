#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
		int H, X, Y, attack = 1;
		cin >> H >> X >> Y;
		H = H - Y;
		if (H > 0) {
			attack += (ceil(H / (float)X));
		}
		cout << attack << "\n";
	}
	return 0;
}
