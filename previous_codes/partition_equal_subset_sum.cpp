// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution {
public:
    bool subsetSum(int a[], int i, int n, int sum)
    {
        if (sum == 0)
            return true;
        if (sum < 0 || i >= n)
            return false;
        return subsetSum(a, i + 1, n, sum - a[i]) || subsetSum(a, i + 1, n, sum);
    }
    bool findPartition(int a[], int n) {
        // code here
        int sum = accumulate(a, a + n, 0);
        if (sum % 2 != 0)
            return false;
        return subsetSum(a, 0, n, sum / 2);
    }
};

class Solution {
public:
    int solve(int *a, int n, int sum, int i, vector<vector<int>>&dp)
    {
        if (sum == 0)
            return 1;
        if (i >= n || sum < 0)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = solve(a, n, sum - a[i], i + 1, dp) || solve(a, n, sum, i + 1, dp);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        sum /= 2;
        vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
        return solve(arr, N, sum, 0, dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends