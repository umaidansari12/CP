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

void solve(int n, int k, vector<int>&r, int sum, vector<vector<int>>&res)
{
	/*if (res.size() == 1)
		return;*/
	if (r.size() == n)
	{
		if (sum % k == 0)
		{
			res.push_back(r);
			return;
		}
		return;
	}
	for (int j = 1; j <= n; j++)
	{
		r.push_back(j);
		solve(n, k, r, sum + j, res);
		r.pop_back();
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		if (n == 1)
		{
			cout << k << endl;
			continue;
		}
		vector<int> r;
		vector<vector<int>> res;
		int sum = 0;
		solve(n, k, r, sum, res);
		int ans = INT_MAX;
		//sort(res.begin(), res.end());
		for (auto i : res)
		{
			int mx = INT_MIN;
			for (auto j : i)
			{
				//cout << j << " ";
				mx = max(mx, j);
			}
			ans = min(mx, ans);
			//cout << endl;
		}
		cout << ans << endl;


	}
	return 0;
}
