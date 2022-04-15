#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n, q, ch;
	cin >> n >> q;
	ll a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (q--)
	{
		cin >> ch;
		if (ch == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			for (int i = l; i <= r; i++)
			{
				a[i] += (ll)(x + i - l) * (ll)(x + i - l);
			}
		}
		else if (ch == 2)
		{
			int y;
			cin >> y;
			cout << a[y] << endl;
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();


	return 0;
}