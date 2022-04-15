#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int a, b, a1, b1, a2, b2;
		cin >> a >> b >> a1 >> b1 >> a2 >> b2;
		if ((a1 == a and b1 == b) or (a1 == b and b1 == a))
			cout << "1\n";
		else if ((a2 == a and b2 == b) or (a2 == b and b2 == a))
			cout << "2\n";
		else
			cout << "0\n";
	}
	return 0;
}
