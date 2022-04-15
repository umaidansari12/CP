#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	vector<int> prime(100001, 1), p, sprime(100001, 0);
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i])
			for (int j = i * i; j <= 10000; j += i)
				prime[j] = 0;
	}
	for (int i = 0; i <= 10000; i++)
	{
		if (prime[i])
			p.push_back(i);
	}
	for (int i = 1; i < p.size() - 1; i++)
	{
		if ((2 * p[i]) > (p[i - 1] + p[i + 1]))
		{
			sprime[p[i]] = 1;
		}
	}
	while (q--)
	{
		int l, r, count = 0;
		cin >> l >> r;
		for (int i = l; i <= r; i++)
		{
			if (sprime[i])
				count++;
		}
		cout << count << endl;
	}

	return 0;
}