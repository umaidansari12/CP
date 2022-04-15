#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin	>> t;
	while (t--) {
		long long int d, l, r;
		cin >> d >> l >> r;
		if (d < l and d < r)
			cout << "Too Early\n";
		else if (d >= l and d <= r)
			cout << "Take second dose now\n";
		else if (d > l and d > r)
			cout << "Too Late\n";
	}


	return 0;
}