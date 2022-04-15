#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int prime[1000001];

/*
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MAX 1000001

bool prime[MAX];

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);
int T;
cin >> T;
memset(prime, true, sizeof(prime));
prime[0] = prime[1] = false;
for (int i = 2; i * i < MAX; i++)
{
	if (prime[i])
	{
		for (int j = i * i; j < MAX; j += i)
		{
			prime[j] = false;
		}
	}
}
while (T--)
{
	int n, ans = INT_MAX;
	cin >> n;
	int t = n;
	if (prime[n])
		cout << 0 << endl;
	else
	{
		while (n > 1)
		{
			for (int i = 2; i * i < MAX; i++)
			{
				if (prime[i] && n % i == 0)
				{
					n /= i;
					ans = min(i, ans);
					//cout << n << " " << i << "\n";
				}
				if (n == 0)
					break;
			}
		}
		//cout << endl;
		cout <<  t - ans << endl;
	}



}


return 0;
}
*/

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/
	int T;
	cin >> T;
	for (int i = 0; i < 1000001; i++)
		prime[i] = i;
	prime[0] = prime[1] = 1;
	for (int i = 2; i < 1000001; i++)
	{
		if (prime[i] == i)
		{
			for (int j = 2 * i; j < MAX; j += i)
			{
				prime[j] = min(prime[j], i);
			}
		}
	}
	while (T--)
	{
		int n;
		cin >> n;
		cout << n - prime[n] << endl;
	}
	return 0;
}