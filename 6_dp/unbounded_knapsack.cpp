// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int helper(int N, int W, int val[], int wt[], vector<vector<int>>&dp)
    {
        if (N == 0 or W == 0)
            return 0;
        if (dp[N][W] != -1)
            return dp[N][W];
        if (wt[N - 1] <= W)
            return dp[N][W] = max(val[N - 1] + helper(N, W - wt[N - 1], val, wt, dp), helper(N - 1, W, val, wt, dp));
        else
            return dp[N][W] = helper(N - 1, W, val, wt, dp);
    }
    int knapSackTopDown(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        return helper(N, W, val, wt, dp);

    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        if (N == 0 or W == 0)
            return 0;
        if (wt[N - 1] <= W)
            return max(val[N - 1] + knapSack(N, W - wt[N - 1], val, wt), knapSack(N - 1, W, val, wt));
        else
            return knapSack(N - 1, W, val, wt);
    }
    int knapSackBottomUp(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (wt[i - 1] <= j)
                    {
                        dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
                    }
                    else if (wt[i - 1] > j)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[N][W];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}  // } Driver Code Ends