#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int maxAmount(int arr[], int n)
	{

		// Your code goes here
		int dp[n][n];
		for (int gap = 0; gap < n; gap++)
		{
			for (int i = 0, j = gap; j < n; i++, j++)
			{
				if (gap == 0)
					dp[i][j] = arr[i];
				else if (gap == 1)
					dp[i][j] = max(arr[i], arr[j]);
				else {
					int val1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
					int val2 = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
					dp[i][j] = max(val1, val2);
				}
			}
		}
		return dp[0][n - 1];

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
		cout << ob.maxAmount(a, n) << "\n";


	}
	return 0;
}
// } Driver Code Ends