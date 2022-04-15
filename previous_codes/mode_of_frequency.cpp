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
		int n;
		cin >> n;
		vector<int> a(n);
		unordered_map<int, int> count;
		vector<int> res(100001);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			count[a[i]]++;
		}
		auto j = count.begin();
		while (j != count.end())
		{
			res[j->second]++;
			j++;
		}
		int ans = INT_MIN, max = 0;
		for (int i = 0; i < 100001; i++)
		{
			if (res[i] > max)
			{
				max = res[i];
				ans = i;
			}
			if (max == res[i])
				continue;
		}
		cout << ans << endl;
	}
	return 0;
}
