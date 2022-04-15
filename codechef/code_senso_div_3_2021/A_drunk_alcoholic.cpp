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
		int n;
		cin >> n;
		long long int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				ans += 3;
			else
				ans--;
		}
		cout << ans << endl;
	}


	return 0;
}