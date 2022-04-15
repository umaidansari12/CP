#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	ll p;
	cin >> p;
	for (ll b = 2; b <= p; b++)
	{
		for (ll a = 2; a < b; a++)
		{
			if ((p % a) == (p % b))
			{
				cout << a << ' ' << b << '\n';
				return ;
			}
		}
	}
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
		solve();
	}


	return 0;
}