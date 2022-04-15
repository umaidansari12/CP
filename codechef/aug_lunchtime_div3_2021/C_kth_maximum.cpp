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
		int n, k;
		cin >> n >> k;
		int ma = INT_MIN, cnt = 0, a[n + 1] = {0}, idx = -1;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			// if (ma < a[i])
			// {
			// 	ma = max(ma, a[i]);
			// 	idx = i;
			// }
			ma = max(ma, a[i]);
		}
		for (int i = k; i <= n; i++)
		{
			if (a[i] == ma)
				ans += (n - i + 1);
		}
		cout << ans << endl;
		// if (idx == (k - 1))
		// 	cout << k << endl;
		// else if (idx < (k - 1))
		// {
		// 	cout << 0 << endl;
		// }
		// else
		// {
		// 	cout << (n - idx) << endl;
		// }
		// for (int w = k; w <= n; w++) {
		// 	for (int i = 0; i < (n - w) + 1; i++)
		// 	{
		// 		if (a[(i + k) - 1] == ma)
		// 			cnt++;
		// 		//cout << a[(i + k) - 1] << '\n';
		// 		for (int j = i; j < (i + w); j++)
		// 		{
		// 			//cout << a[j] << " ";
		// 		}
		// 		//cout << endl;
		// 	}
		// 	//cout << endl;
		// }
		// cout << cnt << endl;
		// cout << endl;

	}


	return 0;
}