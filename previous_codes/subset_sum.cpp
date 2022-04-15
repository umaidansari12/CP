#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
	vector<vector<int>> mem;
	bool subsetSum(vector<int>& nums, int n, int pos, int sum)
	{
		if (sum == 0) //Sum found
			return true;
		else if (pos >= n || sum < 0) //Out of bounds
			return false;
		if (mem[pos][sum] != -1)
			return mem[pos][sum];

		return mem[pos][sum] = subsetSum(nums, n, pos + 1, sum - nums[pos]) || subsetSum(nums, n, pos + 1, sum);
	}
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i)
			sum += nums[i];

		if (sum & 1)    //ODD sum
			return false;

		mem.clear();
		mem.resize(n + 1, vector<int>(sum / 2 + 1, -1));
		return subsetSum(nums, n, 0, sum / 2);
	}
};


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i)
			sum += nums[i];

		if (sum & 1)    //ODD sum
			return false;

		bool dp[n + 1][sum / 2 + 1];
		//Fill DP table (Subset Sum Problem code)
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= sum / 2; ++j)
			{
				if (i == 0 || j == 0) //Base Case
					dp[i][j] = false;
				else if (nums[i - 1] > j) //SkIP case
					dp[i][j] = dp[i - 1][j];
				else if (nums[i - 1] == j)
					dp[i][j] = true;
				else
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
			}
		return dp[n][sum / 2];
	}
};

class Solution {
	public boolean canPartition(int[] nums) {
		int n = nums.length;
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += nums[i];

		if (sum % 2 == 1)
			return false;

		boolean[][] dp = new boolean[n + 1][sum / 2 + 1];

		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= sum / 2; ++j)
			{
				if (i == 0 || j == 0) //Base Case
					dp[i][j] = false;
				else if (nums[i - 1] > j) //SkIP case
					dp[i][j] = dp[i - 1][j];
				else if (nums[i - 1] == j)
					dp[i][j] = true;
				else
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
			}
		return dp[n][sum / 2];
	}
}

class Solution {
public:
	int solve(vector<int>&a, int n, int sum, int i, vector<vector<int>>&dp)
	{
		if (sum == 0)
			return 1;
		if (i >= n || sum < 0)
			return 0;
		if (dp[i][sum] != -1)
			return dp[i][sum];
		return dp[i][sum] = solve(a, n, sum - a[i], i + 1, dp) || solve(a, n, sum, i + 1, dp);
	}
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % 2 != 0)
			return false;
		sum /= 2;
		vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
		return solve(nums, nums.size(), sum, 0, dp);

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

// A recursive solution for subset sum problem
// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
// Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;

// If last element is greater than sum, then ignore it
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);

	/* else, check if sum can be obtained by any of the following
		(a) including the last element
		(b) excluding the last element */
	return isSubsetSum(set, n - 1, sum) ||
	       isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver program to test above function
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}


// A Dynamic Programming solution for subset sum problem
#include <stdio.h>

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if there is a
	// subset of set[0..j-1] with sum equal to i
	bool subset[n + 1][sum + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty, then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in botton up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j] ||
				               subset[i - 1][j - set[i - 1]];
		}
	}

	/* // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	printf("\n");
	}*/

	return subset[n][sum];
}

// Driver program to test above function
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
// This code is contributed by Arjun Tyagi.
int s(vector<int>&a, int n, int sum, int i, vector<vector<int>>&dp) {
	if (sum == 0)
		return 1;
	if (i >= n || sum < 0)
		return 0;
	if (dp[i][sum] != -1)
		return dp[i][sum];
	return dp[i][sum] = s(a, n, sum - a[i], i + 1, dp) || s(a, n, sum, i + 1, dp);
}
int Solution::solve(vector<int> &A, int B) {
	vector<vector<int>>dp(A.size(), vector<int>(B + 1, -1));
	return s(A, A.size(), B, 0, dp);
}
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

int subsetSum(vector<int>&a, int n, int sum, int i)
{
	if (sum == 0)
		return 1;
	if (i >= n || sum < 0)
		return 0;
	return subsetSum(a, n, sum - a[i], i + 1) + subsetSum(a, n, sum, i + 1);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, sum;
		cin >> n >> sum;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//vector<vector<int>> res;
		//cout << "h\n";
		int ans = subsetSum(a, n, sum, 0);
		//cout << "b\n";
		//cout << res.size() << endl;
		cout << ans << endl;
		if (ans)
			cout << "True\n";
		else
			cout << "False\n";
	}


	return 0;
}
