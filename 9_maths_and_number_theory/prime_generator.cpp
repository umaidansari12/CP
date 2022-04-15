#include <bits/stdc++.h>

using namespace std;
using ll = long long;


// Segmented Sieve Algorithm
// 1 - generate primes till sqrt(r)
// 2 - create a dummy array of size (r-l+1) (max 10^6) and mark that with 1
// 3 - mark all multiples of primes in l-r in dummy

int N = 1000000;
bool prime[1000001] = {false};

void sieve()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= N; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= N; j += i)
			{
				prime[j] = false;
			}
		}

	}
}


vector<int> generatePrimes(int n)
{
	//generate primes till sqrt(r) because those sqrt(r) elements will only mark primes in the range suppose
	//range is 110 to 130 so we will use 2 3 5 7 11 only to mark primes in the range because 13 * 13 = 169 and that is greater in the range

	vector<int> primes;
	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == true)
			primes.push_back(i);
	}
	return primes;
}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();//generate sieve till 10^6 because we need max(sqrt(10^12)) elements
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		//generate all primes till sqrt(r)
		vector<int> primes = generatePrimes(sqrt(r));
		// for (auto i : primes)
		// 	cout << i << " ";
		// cout << endl;
		bool dummyPrime[r - l + 1] = {true};
		memset(dummyPrime, true, sizeof(dummyPrime));
		//vector<bool> dummyPrime(r - l + 1, true);
		for (auto pr : primes)
		{
			int firstMultiple = (l / pr) * pr;
			if (firstMultiple < l)
				firstMultiple += pr;
			for (int j = max(firstMultiple, pr * pr); j <= r; j += pr)
			{
				dummyPrime[j - l] = false;
			}
		}
		if (l == 1)
			dummyPrime[0] = false;// 1 is always composte


		for (int i = l; i <= r; i++) {
			if (dummyPrime[i - l])
				cout << i << "\n";
		}
		//cout << '\n';

	}


	return 0;
}