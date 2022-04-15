// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
	long long sum(int arr[], int from, int to)
	{
		long long total = 0;
		for (int i = from; i <= to; i++)
			total += arr[i];
		return total;
	}
	long long minTime(int arr[], int n, int k)
	{
		// code here
		long long dp[k + 1][n + 1] = {0};
		memset(dp, 0, sizeof(dp));
		// base cases
		// k=1
		for (int i = 1; i <= n; i++)
			dp[1][i] = sum(arr, 0, i - 1);

		// n=1
		for (int i = 1; i <= k; i++)
			dp[i][1] = arr[0];

		// 2 to k partitions
		for (int i = 2; i <= k; i++) { // 2 to n boards
			for (int j = 2; j <= n; j++) {

				// track minimum
				long long best = LLONG_MAX;

				// i-1 th separator before position arr[p=1..j]
				for (int p = 1; p <= j; p++)
					best = min(best, max(dp[i - 1][p],
					                     sum(arr, p, j - 1)));

				dp[i][j] = best;
			}
		}

		// required
		return dp[k][n];

		// return minimum time
	}
};

class SolutionBinarySearch
{
public:
	bool isPossible(int arr[], long long barrier, int n, int k)
	{
		int partition = 1, paints = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > barrier)
				return false;
			if ((paints + arr[i]) > barrier)
			{
				partition++;
				paints = arr[i];
			}
			else
				paints += arr[i];
		}
		if (partition > k)
			return false;
		return true;
	}
	long long minTime(int arr[], int n, int k)
	{
		// code here
		long long low = *max_element(arr, arr + n), high = accumulate(arr, arr + n, 0LL), ans = 0LL, mid;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (isPossible(arr, mid, n, k))
			{
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		return ans;
		// return minimum time
	}
};


#include<bits/stdc++.h>


bool isPossibleHelper(vector<int>& arr, long long barrier, int n, int k)
{
	int partition = 1, paints = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > barrier)
			return false;
		if ((paints + arr[i]) > barrier)
		{
			partition++;
			paints = arr[i];
		}
		else
			paints += arr[i];
	}
	if (partition > k)
		return false;
	return true;
}

int paint(int A, int B, vector<int> &arr) {

	// code here
	int n = arr.size();
	long long low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0LL), ans = 0LL, mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (isPossibleHelper(arr, mid, n, A))
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return (B * ans) % 10000003;
	// return minimum time

}


// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;

		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends