#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int prime[1000001];

void sieve()
{
	int N = 1000000;
	for (int i = 1; i <= N; i++)
		prime[i] = i;
	for (int i = 2; i <= N; i++)
	{
		if (prime[i] == i)
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				prime[j] = min(prime[j], i);
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n;
	cin >> T;
	sieve();
	int res[T];
	for (int i = 0; i < T; i++)
	{
		cin >> n , res[i] = n - prime[n];
	}
	for (int i = 0; i < T; i++)
		cout << res[i] << '\n';

	return 0;
}