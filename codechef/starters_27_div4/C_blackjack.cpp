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
		int a, b;
		cin >> a >> b;

		int ans = 21 - (a + b);
		if (ans > 10)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}


	return 0;
}