#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int prime[1000001];
int a[1000001] = {0};

int sumOfDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

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
	for (int i = 2; i < N; i++)
	{
		int sum = 0;
		if (prime[i])
		{
			sum = sumOfDigits(i);
			if (prime[sum])
				a[i] = 1;
		}
	}
	for (int i = 2; i < N; i++)
		a[i] += a[i - 1];
}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int T, l, r, count = 0;
	cin >> T;
	while (T--)
	{
		count = 0;
		cin >> l >> r;
		/*for (int i = l; i <= r; i++)
		{
			if (prime[i])
			{
				int s = sumOfDigits(i);
				if (prime[s])
					count++;
			}
		}
		cout << count << "\n";*/
		if (l == 1)
			cout << a[r] << "\n";
		else
			cout << a[r] - a[l - 1] << "\n";
	}


	return 0;
}