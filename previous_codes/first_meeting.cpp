#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int prime[1000001];

void sieve()
{
	int N = 1000001;
	prime[0] = prime[1] = 0;
	for (int i = 2; i < N; i++)
		prime[i] = 1;
	for (int i = 2; i < N; i++)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j < N; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sieve();
	int n;
	cin >> n;
	int mx = INT_MIN, mi = INT_MAX;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (prime[a[i]])
		{
			mx = max(mx, a[i]);
			mi = min(mi, a[i]);
		}
	}
	if (mx == INT_MIN && mi == INT_MAX)
		cout << -1 << endl;
	else
		cout << abs(mx - mi) << endl;


	return 0;
}