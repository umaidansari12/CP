#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, x, y;
		cin >> n >> x >> y;
		n += 1;
		if ((n * y) >= x)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}