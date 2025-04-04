#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
	// if we're at index 0, that means we already reached the destination and no. of ways +1
	if (n == 0)
		return 1;
	// if we're at index 1, that means we are 1 step before reaching the destination so 1 more way added
	if (n == 1)
		return 1;
	return climbStairs(n - 1) + climbStairs(n - 2);
}

// TC - O(2^n) - from every stair you're trying 2 options to reach the top
// SC - O(n) - stack calls



int climbStairsMemo(int n, vector<int> &dp) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	if (dp[n] != -1) {
		return dp[n];
	}
	return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
}

// TC - O(n) - atmost n problems, eliminating overlapping subproblems
// SC - O(n) - extra dp_array

int climbStairsTabu(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

// TC - O(n) - atmost n problems, eliminating overlapping subproblems
// SC - O(n) - extra dp_array

int climbStairsSpaceOpti(int n) {
	int prev = 1, second_prev = 1, cur_i = 1;
	for (int i = 2; i <= n; i++) {
		cur_i = prev + second_prev;
		second_prev = prev;
		prev = cur_i;
	}
	return cur_i;
}

// TC - O(n) - atmost n problems, eliminating overlapping subproblems
// SC - O(1) - use of variables

// for test case n<=10^18, matrix exponentiation will be used  that will be able to calculate fibonacci in log(n)


int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> dp(n + 1, -1);
		cout << climbStairs(n) << endl;
		cout << climbStairsMemo(n, dp) << endl;
		cout << climbStairsTabu(n) << endl;
		cout << climbStairsSpaceOpti(n) << endl;
	}
}