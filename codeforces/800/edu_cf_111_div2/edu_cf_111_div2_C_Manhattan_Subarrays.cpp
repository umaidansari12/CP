#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll ans = 2 * n - 1; // not generating 1 length and 2 length subarrays as they're always considered as good instead trying to count all the 1 length and 2 length subarrays and store them in our answer.
	for (ll length = 3; length <= n; length++)
	{
		for (ll j = 0; j < (n - length + 1); j++)
		{
			for (ll i = j; i < (j + length); i++)
			{
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
	cout << "------" << endl;
	return 0;
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