#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MAX 1000000

int prime[MAX] = {1};

void sieve()
{
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= MAX; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
				prime[j] = 0;
		}
	}
}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int t;
	cin >> t;
	/*for (int i = 0; i < MAX; i++)
	{
		if (prime[i])
			cout << i << " ";
	}*/
	//cout << endl;
	while (t--)
	{
		int l, r, count = 0;
		cin >> l >> r;
		int prime_min = INT_MAX, prime_max = INT_MIN;
		for (int i = l; i <= r; i++)
		{
			if (prime[i])
			{
				// prime_min = min(prime_min, i);
				// prime_max = max(prime_max, i);
				count++;
			}
		}
		// if (prime_min == prime_max)
		// 	cout << 0 << endl;
		// else if (prime_min == INT_MAX)
		// 	cout << -1 << endl;
		// else
		// 	cout << (prime_max - prime_min) << endl;
		cout << count << endl;
	}


	return 0;
}