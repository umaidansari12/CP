#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n, q, m;
	cin >> n >> q >> m;
	long long int a[n], pre[n], suf[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	pre[0] = a[0];
	suf[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++)
		pre[i] = (pre[i - 1] * a[i]) % m;
	for (int i = n - 2; i >= 0; i--)
		suf[i] = (a[i] * suf[i + 1]) % m;
	while (q--)
	{
		int i;
		cin >> i;
		i--;
		if (i == 0)
			printf("%lld\n", suf[1]);
		else if (i == n - 1)
			printf("%lld\n", pre[n - 2]);
		else
			printf("%lld\n", (pre[i - 1]*suf[i + 1]) % m);
	}


	return 0;
}