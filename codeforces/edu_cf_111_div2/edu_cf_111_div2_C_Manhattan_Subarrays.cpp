#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll manhattan(ll a, ll b, ll c, ll d)
{
	//cout << a << " " << b << " " << c << " " << d << endl;
	return abs(a - c) + abs(b - d);
}


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
			//cout << "subarray:" << endl;
			bool flag = false;
			for (ll i = j; i < (j + length); i++)
			{
				for (ll k = i + 1; k < (j + length); k++)
				{
					for (ll m = k + 1; m < (j + length); m++)
					{
						ll c = manhattan(a[i], i, a[m], m);
						ll d = manhattan(a[i], i, a[k], k);
						ll e = manhattan(a[k], k, a[m], m);
						//cout << c << " " << d << " " << e << endl;
						//cout << endl;
						if (c == (d + e))
						{
							flag = true;
							break;
						}

					}
				}
				//cout << a[i] << " ";
			}
			if (!flag)
				ans++;
			//cout << endl;
		}
		//cout << endl;
	}
	//cout << "------" << endl;
	return ans;
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