#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
	int solve(int arr[], int n, int s1, int s2, vector<vector<int>> &dp)
	{
		if (n < 0)
			return abs(s1 - s2);
		if (dp[n][s1] != -1)
			return dp[n][s1];
		return dp[n][s1] = min(solve(arr, n - 1, s1, s2, dp), solve(arr, n - 1, s1 + arr[n], s2 - arr[n], dp));
	}
	int minDiffernce(int arr[], int n)
	{
		// Your code goes here
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		return solve(arr, n - 1, 0, sum, dp);
	}
};


// { Driver Code Starts.
int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.minDiffernce(a, n) << "\n";

	}
	return 0;
}  // } Driver Code Ends