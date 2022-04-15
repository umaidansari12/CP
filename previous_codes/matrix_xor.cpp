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
	while (t--)
	{
		/*ll n, m, k, xr = 0;
		cin >> n >> m >> k;
		ll mi = (k + 2);
		ll mx = (k + n + m);
		ll ans = mi ^ mx;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				xr ^= (k + i + j);
		}
		cout << ans << endl;*/
		int n, m, k, xr = 0;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
		{
			if (min(i, m) % 2)
				xr ^= (k + i + 1);
		}
		for (int i = 2; i <= m; i++)
		{
			if (min(n, m - i + 1) % 2)
				xr ^= (k + n + i);
		}
		cout << xr << endl;
	}


	return 0;
}