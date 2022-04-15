// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void solve(int n, vector<vector<int>> Matrix, int r, int c, int sum, int &ans)
    {
        ans = max(sum, ans);
        if ((r + 1) < n and c < n)
            solve(n, Matrix, r + 1, c, sum + Matrix[r + 1][c], ans);
        if ((r + 1) < n and (c + 1) < n)
            solve(n, Matrix, r + 1, c + 1, sum + Matrix[r + 1][c + 1], ans);
        if ((r + 1) < n and (c - 1) >= 0)
            solve(n, Matrix, r + 1, c - 1, sum + Matrix[r + 1][c - 1], ans);
    }
    int maximumPathRecursive(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, 0));
        if (N == 1)
            return Matrix[0][0];
        int ans = 0;
        for (int i = 0; i < N; i++)
            solve(N, Matrix, 0, 0, Matrix[0][i], ans);
        return ans;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, 0));
        if (N == 1)
            return Matrix[0][0];
        for (int i = 0; i < N; i++)
            dp[0][i] = Matrix[0][i];
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int maxSum = INT_MIN;
                maxSum = max(maxSum, dp[i - 1][j]);
                if ((j - 1) >= 0 and maxSum < dp[i - 1][j - 1])
                    maxSum = dp[i - 1][j - 1];
                if ((j + 1) < N and maxSum < dp[i - 1][j + 1])
                    maxSum = dp[i - 1][j + 1];
                dp[i][j] = maxSum + Matrix[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans = max(ans, dp[N - 1][i]);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}  // } Driver Code Ends