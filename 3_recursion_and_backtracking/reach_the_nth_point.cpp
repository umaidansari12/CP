#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

	int nthPointSolve(int n, vector<long long int> &dp, int mod) {
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;

		if (dp[n] != -1)
			return dp[n];

		return dp[n] = (nthPointSolve(n - 1, dp, mod) % mod + nthPointSolve(n - 2, dp, mod) % mod) % mod;
	}
	int nthPoint(int n) {
		// Code here

		vector<long long int> dp(n + 1, -1);
		int mod = 1e9 + 7;

		return nthPointSolve(n, dp, mod);


	}
	int nthPointRecur(int n) {
		// Code here
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;

		return nthPoint(n - 1) + nthPoint(n - 2);


	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends