#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < a and c < b)
		{
			cout << "Alice\n";
		}
		else if (b < a and b < c)
		{
			cout << "Bob\n";
		}
		else
			cout << "Draw\n";
	}
	return 0;
}
