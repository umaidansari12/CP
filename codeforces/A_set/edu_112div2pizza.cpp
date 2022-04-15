#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
// int a[] = {6, 8, 10};
// int b[] = {15, 20, 25};

vector<pair<int, int>> a = {{6, 15}, {8, 20}, {10, 25}};

//int dp[10000000][4];
void solve(ll s, ll n, ll time, int idx, ll &res)
{
	if (s >= n)
	{
		if (time != 0)
			res = min(res, time);
		return;
	}
	if (idx == 3)
		return;
	// if (dp[s][idx] != -1)
	// 	return dp[s][idx];

	// solve(s + a[idx], n, time + b[idx], idx, res);
	// solve(s , n, time , idx + 1, res);
	solve(s + a[idx].first, n, time + a[idx].second, idx, res);
	solve(s , n, time , idx + 1, res);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n <= 6)
		{
			cout << "15\n";
		}
		else
		{
			if (n % 2 != 0)
				n++;
			cout << (n / 2) * 5LL << "\n";

		}
		// ll res = LLONG_MAX;
		// //memset(dp, -1, sizeof(dp));
		// solve(0, n, 0, 0, res);
		// cout << res << '\n';
	}


	return 0;
}