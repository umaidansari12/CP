#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if ((x % 2) == 0 and (y % 2) == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}