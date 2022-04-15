#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve()
{
	int n;
	ll cnt = 0;
	cin >> n;
	ll a[n + 1];
	pair<ll, ll> br[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		br[i] = {a[i], i};
	}
	sort(br + 1, br + n + 1);
	// for (int i = 0; i < n - 1; i++)
	// {
	// 	for (int j = i + 1; j < n; j++)
	// 	{
	// 		if ((a[i]*a[j]) == (i + j + 2))
	// 			cnt++;
	// 	}
	// }
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = i + 1; j <= n; j++)
		{
			ll L = br[i].second + br[j].second;
			ll R = br[j].first * br[i].first;
			if (L == R)
				cnt++;
			if (R > (2 * n))
				break;
		}
	}
	/*unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		if (m.find(a[i] - i) != m.end())
			cnt += m[a[i] - i];
		m[(i + 2) / a[i]]++;
	}*/
	return cnt;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << endl;
	}

	return 0;
}