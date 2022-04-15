#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool prime[10000001];
ll pre[10000001];

void sieve()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 10000000; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= 10000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	pre[0] = 0;
	for (int i = 1; i <= 10000000; i++)
	{
		pre[i] = pre[i - 1] + (int)prime[i];
	}

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	sieve();
	while (t--) {
		int n, m;
		cin >> m >> n;
		if (m == 0)
		{
			cout << pre[n] << '\n';
		}
		else
		{
			cout << pre[n] - pre[m - 1] << '\n';
		}

	}


	return 0;
}