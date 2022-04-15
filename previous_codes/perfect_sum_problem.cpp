#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {

public:
    int subsetSum(int *a, int n, int sum, int i, vector<vector<int>>&dp)
    {
        if (sum == 0)
            return 1;
        if (i >= n || sum < 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = (subsetSum(a, n, sum - a[i], i + 1, dp) % 1000000007 + subsetSum(a, n, sum, i + 1, dp) % 1000000007) % 1000000007;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        return subsetSum(arr, n, sum, 0, dp) % 1000000007;
    }

};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";

    }
    return 0;
}
// } Driver Code Ends