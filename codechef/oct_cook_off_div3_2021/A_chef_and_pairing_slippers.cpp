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
		int n, l, x;
		cin >> n >> l >> x;
		cout << min(l, n - l)*x << endl;
	}


	return 0;
}