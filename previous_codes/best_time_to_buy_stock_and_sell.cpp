#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int maxProfitOptimal(vector<int>& prices) {
	// Find minimum from left side and this will maximize your profit and try selling on every day right
	int n = prices.size(), profit = 0, mi = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		mi = min(mi, prices[i]);
		profit = max(profit, prices[i] - mi);
	}
	return profit;

}

int maxProfitBrute(vector<int>& prices) {
	int n = prices.size(), profit = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (prices[j] > prices[i])
				profit = max(profit, prices[j] - prices[i]);
		}
	}
	return profit;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, profit = 0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//O(n^2) approach
		/*for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] > a[i])
					profit = max(profit, a[j] - a[i]);
			}
		}
		cout << profit << endl;*/
	}


	return 0;
}