#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int climbingStairs(int n, vector<int>& dp)
{
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return 0;
	}
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = climbingStairs(n - 1, dp) + climbingStairs(n - 2, dp);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, count = 0;
		cin >> n;
		vector<int> dp(n + 1, -1);
		cout << climbingStairs(n, dp) << endl;
	}


	return 0;
}