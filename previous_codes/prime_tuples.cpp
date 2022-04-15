#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	vector<long long int> prime(100000, 1);

	for (int i = 2; i * i <= 100000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	vector<int> res;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i])
			res.push_back(i);
	}
	/*for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;*/

	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n, count = 0;
		cin >> n;
		for (int i = 0; i < res.size(); i++)
		{
			if (res[i] > n || res[i + 1] > n || res[i + 2] > n)
				break;
			if ((res[i] + res[i + 1] == res[i + 2]))
				count++;
		}
		/*for (int i = 2; i <= n - 2; i++)
		{
			if (prime[i])
			{
				for (int j = i + 1; j <= n - 1; j ++)
				{
					if (prime[j])
					{
						for (int k = j + 1; k <= n; k ++)
						{
							if (prime[k] && (i + j == k))
							{
								count++;
							}
						}
					}
				}

			}

		}*/
		cout << count << endl;
	}
	return 0;
}
