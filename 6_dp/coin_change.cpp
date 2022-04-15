#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution1 {
public:
    int solve(vector<int>c, int s, int m, int i, vector<vector<int>>&dp)
    {
        if (i >= m || s < 0)
            return 0;
        if (s == 0)
            return 1;
        if (dp[i][s] != -1)
            return dp[i][s];
        return dp[i][s] = solve(c, s - c[i], m, i, dp) + solve(c, s, m, i + 1, dp);
    }
    int change(int amount, vector<int>& coins) {
        if (coins.size() == 0 && amount == 0)
            return 1;
        if (coins.size() == 0)
            return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins, amount, coins.size(), 0, dp);

    }
};
class Solution
{
public:
    long long int countBottomUp( int S[], int m, int n )
    {
        //code here
        vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, -1));
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 and j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0)
                {
                    dp[i][j] = 0;
                }
                else if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if (S[i - 1] <= j)
                    {
                        dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];

    }
    long long int countHelper(int S[], int m, int n , vector<vector<long long int>>&dp)
    {
        if (m == 0 and n == 0)
        {
            return 1;
        }
        if (m == 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        if (S[m - 1] <= n)
            return dp[m][n] = (long long int)countHelper(S, m - 1, n, dp) + (long long int)countHelper(S, m, n - S[m - 1], dp);
        else
            return dp[m][n] = (long long int)countHelper(S, m - 1, n, dp);
    }
    long long int countTopDown( int S[], int m, int n )
    {
        //code here
        vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, -1));
        return countHelper(S, m, n, dp);

    }
    long long int count( int S[], int m, int n )
    {
        //code here.
        if (m == 0 and n == 0)
        {
            return 1;
        }
        if (m == 0)
            return 0;
        if (S[m - 1] <= n)
            return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
        else
            return count(S, m - 1, n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }


    return 0;
}  // } Driver Code Ends