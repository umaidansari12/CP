#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int prime[10001];
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 10000; i++)
	{
		prime[i] = 1;
	}
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
				prime[j] = 0;
		}
	}
	while (t--)
	{
		int n, ans1 = -1, ans2 = -1;
		cin >> n;
		for (int i = 2; i <= (n / 2); i++)
		{
			if (prime[i])
			{
				if (prime[n - i])
				{
					ans1 = i;
					ans2 = n - i;
					break;
				}
			}
		}
		cout << ans1 << " " << ans2 << endl;

	}


	return 0;
}