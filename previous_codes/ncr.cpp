#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int nCr(int n, int r) {
		// code here
		int res = 1, mod = 1e9 + 7;
		if (r > n)
			return 0;
		if (r > n - r)
			r = n - r;
		vector<int> dp(r + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = min(i, r); j > 0; j--)
			{
				dp[j] = (dp[j] + dp[j - 1]) % mod;
			}
		}
		return dp[r];
	}
};

int binomialCoefficient(int n, int k)
{
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;
	return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
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
		int n, r;
		cin >> n >> r;
		int res = 1;
		for (int i = 1; i <= n; i++)
		{
			res *= (n - r + i);
			res /= i;
		}
		cout << res << endl;
	}


	return 0;
}