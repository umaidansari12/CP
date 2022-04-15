#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n)
{
	// Your code here
	//when things happen to you assume the worst but when you do the things do the best
	// so main strategy lies in when i will choose i will choose maxmum out of the available choices but when opponent chooses he will try to give me the minimum out of the both choics i.e he will choose maximum for himself and minimum for myself
	long long dp[n][n];
	for (int gap = 0; gap < n; gap++)
	{
		for (int i = 0, j = gap; j < n; i++, j++)
		{
			if (gap == 0)
				dp[i][j] = arr[i];
			else if (gap == 1)
				dp[i][j] = max(arr[i], arr[j]);
			else
			{
				int val1 = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
				int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
				dp[i][j] = max(val1, val2);
			}

		}
	}
	return dp[0][n - 1];
}

// { Driver Code Starts.

int main() {

	//taking total testcases
	int T;
	cin >> T;
	while (T--)
	{
		//taking number of elements
		int N;
		cin >> N;

		int A[N];

		//inserting the elements
		for (int i = 0; i < N; i++)
			cin >> A[i];

		//calling function maximumAmount()
		cout << maximumAmount(A, N) << endl;

	}
	return 0;
}  // } Driver Code Ends