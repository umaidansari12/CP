#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, e, h, a, b, c, ans = 1e18;
		cin >> n >> e >> h >> a >> b >> c ;
		for (ll n_cakes = 0; n_cakes <= n; n_cakes++)
		{
			ll maxO = 0, maxM = 0, reqO = 0, reqM = 0;
			if (e < n_cakes || h < n_cakes)
			{
				//ans = -1;
				break;
			}
			else
			{
				maxO = (e - n_cakes) / 2;
				maxM = (h - n_cakes) / 3;

			}

			if (n_cakes + maxO + maxM < n)
			{
				continue;
			}
			else
			{
				if (a < b)
				{
					reqO = min(n - n_cakes, maxO);
					reqM = n - n_cakes - reqO;
				}
				else
				{
					reqM = min(n - n_cakes, maxM);
					reqO = n - n_cakes - reqM;
				}
			}
			ll price = (n_cakes * c) + (reqO * a) + (reqM * b);
			ans = min(ans, price);
		}
		if (ans == 1e18)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}


	return 0;
}