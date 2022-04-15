#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q, l, r;
	cin >> n >> q;
	ll a[n + 1], pre[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 1)
			pre[i] = a[i];
		else
			pre[i] = a[i] + pre[i - 1];
	}
	while (q--)
	{
		cin >> l >> r;
		if (l == 1)
			cout << pre[r] << '\n';
		else
			cout << pre[r] - pre[l - 1] << '\n';
	}


	return 0;
}