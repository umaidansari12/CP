#include <bits/stdc++.h>

using namespace std;
using ll = long long;


// ll solveBetter()
// {
// 	ll n, cnt = 0;
// 	cin >> n;
// 	ll a[n];
// 	memset(a, 0LL, sizeof(a));
// 	unordered_map<ll, ll> m;
// 	for (ll i = 0; i < n; i++)
// 	{
// 		a[i] = i + 1;
// 		m[a[i]]++;
// 	}
// 	for (ll i = 0; i < n; i++)
// 	{
// 		for (ll j = 0; j < n; j++)
// 		{
// 			if ((m.find(a[i] % a[j]) != m.end()) and (a[j] % (a[i] % a[j])) == 0)
// 				cnt++;
// 		}
// 	}
// 	return cnt;
// }

long long int solve()
{
	long long int n, cnt = 0LL;
	cin >> n;
	long long int a[n];
	memset(a, 0LL, sizeof(a));
	//cout << n << "\n";
	for (long long int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		//cout << a[i] << " ";
	}
	//cout << endl;
	for (long long int i = 0; i < n; i++)
	{
		//cout << i << " ";
		for (long long int j = 0; j < n; j++)
		{
			//cout << j << " ";
			long long int num1 = (a[i] % a[j]);
			if (num1 == 0)
				continue;
			long long int num2 = (a[j] % num1);
			if ((num1 >= 1) and (num1 <= n) and (num2 == 0))
			{
				cnt++;
			}
		}
	}
	return cnt;
}


// ll solveBrute()
// {
// 	ll n, cnt = 0;
// 	cin >> n;
// 	ll a[n];
// 	memset(a, 0LL, sizeof(a));
// 	for (ll i = 0; i < n; i++)
// 	{
// 		a[i] = i + 1;
// 	}
// 	for (ll i = 0; i < n; i++)
// 	{
// 		for (ll j = 0; j < n; j++)
// 		{
// 			for (ll k = 0; k < n; k++)
// 			{
// 				if ((((a[i] % a[j]) == a[k]) and ((a[j] % a[k]) == 0)))
// 				{
// 					cnt++;
// 				}
// 			}
// 		}
// 	}
// 	return cnt;
// }

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << '\n';
	}
	return 0;
}