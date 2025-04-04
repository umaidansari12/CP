#include <bits/stdc++.h>

using namespace std;

/*
Q - why will greedy solution fail?
because at that moment, you're making choice on the basis of next best choice available and
I - 10 20 30 10 -> here greedy will pass, as you can make jump to 20 from 10, which is minimal, then from 20 to 10, which will take another 10, so the overall minimal energy used will be 20, and the maximum will be 40
O - 20 - min ,40 max
I - 30 10 60 10 60 50
O - Here if we take min jump which going to 10 from 30, it will take 20 energy, will again move from 10 to 10, which will take 0, then from 10 to 50, which will take 40 energy so total energy used is - 20 + 0 + 40
Now if we use dp and make a jump from 30 to 60, 30 energy will be used, then from 60 will move to 60, 0 energy will be used, 60 to 50, 10 energy will be used - 30 + 0 + 10 - total minimum 40 energy will be used
*/

int frogKJump(int index, int k, vector<int> &heights) {
	// f(index) - minimum total energy used to reach index
	// base case - no energy used to reach at 0th index
	if (index == 0)
		return 0;
	int ans = INT_MAX;
	for (int i = 1; i <= k; i++) {
		if (index - i >= 0)
			ans = min(ans, frogKJump(index - i, k, heights) + abs(heights[index] - heights[index - i]));
	}
	return ans;
}

// TC - trying all possible solutions, for every index we've k options - O(k^n)
// SC - O(n) - n levels deep

int frogKJumpMemo(int index, int k, vector<int> &heights, vector<int> &dp) {
	if (index == 0)
		return 0;
	if (dp[index] != INT_MAX)
		return dp[index];
	for (int i = 1; i <= k; i++) {
		if (index - i >= 0) {
			dp[index] = min(dp[index], frogKJumpMemo(index - i, k, heights, dp) + abs(heights[index] - heights[index - i]));
		}
	}

	return dp[index];
}

// TC - O(n*k)
// SC - O(n) + O(n) -> stack space + dp_array

int frogKJumpTabu(int n, int k, vector<int> &heights) {
	// 1 approach
	vector<int> dp(n, INT_MAX);
	dp[0] = 0; // energy required to reach at 0th index
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
			}
		}
	}
	return dp[n - 1];
}

// TC - O(n*k)
// SC - O(n) -> dp_array - reduced stack space

int frogJumpSpaceOptimized(int n, int k, vector<int> &heights) {

	vector<int> dp(k, 0);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			// if (index - )
		}
	}
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

// At times you will need only last k values to compute the next value

// TC - O(N)
// SC - O(k)


int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> heights(n, 0), dp(n, INT_MAX);
		for (int i = 0; i < n; i++)
			cin >> heights[i];
		cout << frogKJump(n - 1, k, heights) << endl;
		cout << frogKJumpMemo(n - 1, k, heights, dp) << endl;
		cout << frogKJumpTabu(n, k, heights) << endl;
	}
}

// Test Case -

// Input -
// 3
// 3 1
// 2 5 2
// 4 2
// 10 40 30 10
// 5 3
// 10 40 50 20 60

// Output -
// 6
// 6
// 6
// 40
// 40
// 40
// 50
// 50
// 50