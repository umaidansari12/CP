#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long mod = 1e9 + 7;
    long long solve(int N, int M, int X, vector<vector<long long>> &dp) {
        if (N == 0 and X == 0)
            return 1;
        if (N <= 0 or X <= 0)
            return 0;
        if (dp[N][X] != -1) {
            return dp[N][X];
        }
        long long res = 0;
        for (int i = 1; i <= M; i++) {
            res += (solve(N - 1, M, X - i, dp));
        }
        dp[N][X] = res;
        return res;
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
        return solve(N, M, X, dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}  // } Driver Code Ends