#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool prime[1000001];

void sieve()
{
	int N = 1000000;
	for (int i = 0; i <= N; i++)
		prime[i] = true;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= N; i++)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				prime[j] = false;
			}
		}
	}
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	sieve();
	while (T--)
	{
		int l, r, c = 0;
		cin >> l >> r;
		for (int i = l; i <= r; i++)
			if (prime[i])
				c++;
		cout << c << endl;
	}


	return 0;
}