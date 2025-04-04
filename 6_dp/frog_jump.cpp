#include <bits/stdc++.h>

using namespace std;

int frogJump(int index, vector<int> &heights) {
	// f(index) - minimum total energy used to reach index
	// base case - no energy used to reach at 0th index
	if (index == 0)
		return 0;
	// energy to reach index + losing energy to reach index-1
	int left = frogJump(index - 1, heights) + abs(heights[index] - heights[index - 1]);
	int right = INT_MAX;
	if (index > 1) {
		right = frogJump(index - 2, heights) + abs(heights[index] - heights[index - 2]);
	}
	return min(left, right);
}

// TC - trying all possible solutions, for every index we've 2 options - O(2^n)
// SC - O(n) - n levels deep

int frogJumpMemo(int index, vector<int> &heights, vector<int> &dp) {
	if (index == 0)
		return 0;
	if (dp[index] != INT_MAX)
		return dp[index];
	int left = frogJumpMemo(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
	int right = INT_MAX;
	if (index > 1) {
		right = frogJumpMemo(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
	}
	return dp[index] = min(left, right);
}

// TC - O(n)
// SC - O(n) + O(n) -> stack space + dp_array

int frogJumpTabu(int n, vector<int> &heights) {
	// 1 approach
	// vector<int> dp(n, INT_MAX);
	// dp[0] = 0; // energy required to reach at 0th index
	// for (int i = 1; i < n; i++) {
	// 	int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
	// 	int right = INT_MAX;
	// 	if (i >= 2)
	// 		right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
	// 	dp[i] = min(left, right);
	// }
	// return dp[n - 1];
	// 2 approach
	vector<int> dp(n, INT_MAX);
	dp[0] = 0; // energy required to reach at 0th index
	dp[1] = heights[1] - heights[0]; // energy required to reach at 1th index, only possible option to take a jump from 0
	for (int i = 2; i < n; i++) {
		int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
		int right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
		dp[i] = min(left, right);
	}
	return dp[n - 1];
}

// TC - O(n)
// SC - O(n) -> dp_array - reduced stack space

int frogJumpSpaceOptimized(int n, vector<int> &heights) {
	// int minSteps = 0, firstStep = 0, secondStep = abs(heights[1] - heights[0]);
	// for (int i = 2; i < n; i++) {
	// 	minSteps = min(firstStep + abs(heights[i] - heights[i - 2]), secondStep + abs(heights[i] - heights[i - 1]));
	// 	firstStep = secondStep;
	// 	secondStep = minSteps;
	// }
	// return minSteps;
	int cur_i = 0, prev_i = 0, prev_2i = 0, fs = 0, ss = 0;
	for (int i = 1; i < n; i++) {
		fs = prev_i + abs(heights[i] - heights[i - 1]);
		ss = INT_MAX;
		if (i > 1)
			ss = prev_2i + abs(heights[i] - heights[i - 2]);
		cur_i = min(fs, ss);
		prev_2i = prev_i;
		prev_i = cur_i;
	}
	return cur_i;
}

// TC - O(N)
// SC - O(1)

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> heights(n, 0), dp(n, INT_MAX);
		for (int i = 0; i < n; i++)
			cin >> heights[i];
		cout << frogJump(n - 1, heights) << endl;
		cout << frogJumpMemo(n - 1, heights, dp) << endl;
		cout << frogJumpTabu(n, heights) << endl;
		cout << frogJumpSpaceOptimized(n, heights) << endl;
	}
}

// Test Case
// Input
// 4
// 10 20 30 10
// 3
// 10 50 10
// 8
// 7 4 4 2 6 6 3 4
// 6
// 4 8 3 10 4 4

// Output
// 20
// 0
// 7
// 2