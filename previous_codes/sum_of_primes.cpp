#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void prime_sieve(int n)
{

	bool prime[1000001] = {true};

	for (ll p = 2; p * p <= 1000001; p++)
	{
		if (prime[p] == true)
		{
			for (ll i = p * p; i <= 1000001; i += p)
				prime[i] = false;
		}
	}
}

void sumOfPrimes(ll n)

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		sumOfPrimes(n);
	}


	return 0;
}