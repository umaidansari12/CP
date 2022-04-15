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
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n;;
		cin >> n;
		vector<long long int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		long long int ans = 0;
		long long int x = a[0], y = a[1], z = a[n - 1];
		ans = max(ans, abs(x - y) + abs(y - z) + abs(z - x));
		/*y = a[0];
		ans = max(ans, abs(x - y) + abs(y - z) + abs(z - x));
		x = a[1];
		y = a[1];
		ans = max(ans, abs(x - y) + abs(y - z) + abs(z - x));*/
		/*for (int i = 0; i < n - 2; i++)
		{
			long long int x = abs(a[i] - a[i + 1]), y = abs(a[i + 1] - a[i + 2]), z = abs(a[i + 2] - a[i]);
			ans = max(ans, x + y + z);
		}
		//int x = abs(a[n - 3] - a[n - 2]), y = abs(a[n - 2] - a[n - 1]), z = abs(a[n - 1] - a[n - 3]);
		int x = abs(a[0] - a[1]), y = abs(a[1] - a[2]), z = abs(a[2] - a[0]);
		ans = max(ans, x + y + z);
		/*for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					int x = abs(a[i] - a[j]), y = abs(a[j] - a[k]), z = abs(a[k] - a[i]);
					ans = max(ans, x + y + z);
				}
			}
		}*/
		cout << ans << endl;
	}
	return 0;
}
