#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int n, x, p;
		cin >> n >> x >> p;
		long long int correct = 3 * x;
		long long int incorrect = (n - x);
		if ((correct - incorrect) >= p)
			cout << "PASS\n";
		else
			cout << "FAIL\n";
	}
	return 0;
}
