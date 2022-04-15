#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct rod {
	int length;
	int price;
};

int maximizeTheCuts(int n, int x, int y, int z)
{
	//Your code here
	vector<int>dp(n + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i - x >= 0)
			dp[i] = max(dp[i], dp[i - x]);
		if (i - y >= 0)
			dp[i] = max(dp[i], dp[i - y]);
		if (i - z >= 0)
			dp[i] = max(dp[i], dp[i - z]);
		if (dp[i] != -1)
			dp[i]++;
	}
	return max(dp[n], 0);
}

int rodCutting(vector<rod>&rd, int n, int w, int i, vector<vector<int>>&dp)
{
	if (i >= n)
		return 0;
	if (w == 0)
		return 0;
	if (dp[i][w] != -1)
		return dp[i][w];
	if (rd[i].length <= w)
	{
		return (max(rd[i].price + rodCutting(rd, n, w - rd[i].length, i, dp), rodCutting(rd, n, w, i + 1, dp)));
	}
	else
	{
		return rodCutting(rd, n, w, i + 1, dp);
	}
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
		int n, price;
		cin >> n;
		vector<rod> rd(n);
		for (int i = 0; i < n; i++)
		{
			cin >> price;
			rd[i].length = i + 1;
			rd[i].price = price;
		}
		vector<vector<int>>dp(n, vector<int>(n + 1, -1));
		cout << rodCutting(rd, n, n, 0, dp) << endl;

	}


	return 0;
}