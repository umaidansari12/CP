#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct knapsack {
	int values;
	int weights;
};

bool cmp(knapsack a, knapsack b)
{
	return a.values > b.values;
}

/*void knapsack01(vector<knapsack>&k, int n, int w, int i)
{
	if (i == n)
		return ;
	if (w == 0)
	{
		return ;
	}
	if (w - k[i].weights >= 0)
	{
		res += k[i].values;
		knapsack01(k, n, w - k[i].weights, i + 1, res);
	}
}*/
int knapsack01(vector<knapsack>&k, int n, int w, int i)
{
	if (i >= n)
		return 0;
	if (w == 0)
		return 0;
	if (k[i].weights <= w)
	{
		return max(k[i].values + knapsack01(k, n, w - k[i].weights, i + 1), knapsack01(k, n, w, i + 1));
	}
	else
	{
		return knapsack01(k, n, w, i + 1);
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int knapsack01(int wt[], int val[], int n, int w, int i, vector<vector<int>>&dp)
{
	if (i >= n)
		return 0;
	if (w == 0)
		return 0;
	if (dp[i][w] != -1)
		return dp[i][w];
	if (wt[i] <= w)
	{
		return dp[i][w] = max(val[i] + knapsack01(wt, val, n, w - wt[i], i + 1, dp), knapsack01(wt, val, n, w, i + 1, dp));
	}
	else
	{
		return dp[i][w] = knapsack01(wt, val, n, w, i + 1, dp);
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
		int n, values, weights, w;
		cin >> n >> w;
		vector<knapsack> k(n);
		for (int i = 0; i < n; i++)
		{
			cin >> values >> weights;
			k[i].values = values;
			k[i].weights = weights;
		}
		/*sort(k.begin(), k.end(), cmp);
		for (auto i : k)
		{
			cout << i.values << " " << i.weights << endl;
		}*/
		//vector<vector<int>>()

		cout << knapsack01(k, n, w, 0) << endl;

	}


	return 0;
}