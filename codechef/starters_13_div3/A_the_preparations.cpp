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
		long long int m, n, k;
		cin >> m >> n >> k;
		if ((n * k) < m)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}