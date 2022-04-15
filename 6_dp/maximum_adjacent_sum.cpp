#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maximumAdjacentSum(vector<int>&a, int n)
{
	vector<int> dp(n, 0);
	dp[0] = max(a[0], 0);
	dp[1] = max(0, max(a[0], a[1]));
	for (int i = 2; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
	}
	return dp[n - 1];
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << maximumAdjacentSum(a, n) << endl;
	}


	return 0;
}