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
		int n, m;
		cin >> n >> m;
		map<ll, ll> mp;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			mp[x % m]++;
		}
		int ans = 0;
		for (auto i : mp)
		{
			if (i.first == 0 && i.second > 0)ans++;
			else if (mp.count(m - i.first) == 0) ans += i.second;
			else if (m - i.first == i.first) ans++;
			else if (m - i.first > i.first)
			{
				ll a = i.second;
				ll b = mp[m - i.first];
				if (abs(a - b) <= 1) ans++;
				else if (a > b)
				{
					a -= (b + 1);
					ans++;
					ans += a;
				}
				else
				{
					b -= (a + 1);
					ans++;
					ans += b;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
