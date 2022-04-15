// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
	int mod = 1e9 + 7;
	int ncr(int n, int r, vector<vector<int>> &dp) {
		if (r > n)
			return 0;

		if (r == 0 or r == n)
			return 1;

		if (dp[n][r] != -1)
			return dp[n][r];

		return dp[n][r] = (ncr(n - 1, r - 1, dp) % mod + ncr(n - 1, r, dp) % mod) % mod;

	}
	int nCrTopDown(int n, int r) {
		// code here
		vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
		return ncr(n, r, dp);
	}
	int nCrRecur(int n, int r) {
		// code here
		if (r > n)
			return 0;
		if (r == 0 or r == n)
			return 1;

		return nCr(n - 1, r - 1) + nCr(n - 1, r);
	}
	int mod = 1e9 + 7;
	int nCr(int n, int r) {
		// code here
		vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
		//base case initialization
		// C(n,0) = 1;
		// C(n,n) = 1;
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= r; j++) {
				// C(n,k) = C(n-1,k-1)+C(n-1,k)
				dp[i][j] = ((dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod)) % mod;
			}
		}

		return dp[n][r];
	}
	int nCr(int n, int r) {
		// code here
		vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= min(i, r); j++) {
				if (j == 0 or j == i) {
					//base case initialization
					// C(n,0) = 1;
					// C(n,n) = 1;
					dp[i][j] = 1;

				}
				else {
					// C(n,k) = C(n-1,k-1)+C(n-1,k)
					dp[i][j] = ((dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod)) % mod;
				}
			}

		}

		return dp[n][r];
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, r;
		cin >> n >> r;

		Solution ob;
		cout << ob.nCr(n, r) << endl;
	}
	return 0;
}  // } Driver Code Ends