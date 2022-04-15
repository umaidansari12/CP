#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string getBinaryString(ll i, ll n)
{
	ll c = 0;
	string s;
	while (i > 0)
	{
		s += (to_string(i % 2));
		i /= 2;
		c++;
	}
	while (c < n)
	{
		s += '0';
		c++;
	}
	return s;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	ans = max(ans, k ^ 0);
	for (ll i = 1; i <= pow(2, n) - 1; i++)
	{
		string b = getBinaryString(i, n);
		ll xr = 0;
		for (int j = 0; j < b.size(); j++)
			if (b[j] == '1')
				xr ^= a[j];
		ans = max(ans, k ^ xr);
	}
	cout << ans << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}