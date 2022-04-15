#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> ar(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	while (q--)
	{
		ll a;
		cin >> a;
		ll p = lower_bound(ar.begin(), ar.end(), a) - ar.begin();
		if (p < n and ar[p] == a)
			cout << "0\n";
		else if (p % 2 == 0)
			cout << "POSITIVE\n";
		else
			cout << "NEGATIVE\n";
	}

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();


	return 0;
}