#include <bits/stdc++.h>

using namespace std;

// memoization approach
// TC - O(n) -> atmost n deeper calls
// SC - O(n) -> n size recursion stack + O(n) -> dp_array
int fibMemo(int n, vector<int> &dp) {
	if (n <= 1)
		return n;
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

// tabulation approach
// TC - O(n) -> atmost n iterations to solve all problems
// SC - O(n) -> dp_array -> eliminated recursion calls

int fibTab(int n, vector<int> &dp) {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

// space optimized tabulation approach
// TC - O(n)
// SC - O(1)
// approach in recurrence relation, 2 variables were used, so define those variables and start updating value at every subproblem iteration

int fib(int n) {
	int prev = 1, second_prev = 0, cur_i;
	for (int i = 2; i <= n; i++) {
		cur_i = prev + second_prev;
		second_prev = prev;
		prev = cur_i;
	}
	return cur_i;
}

// for test case n<=10^18, matrix exponentiation will be used  that will be able to calculate fibonacci in log(n)

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> dp(n + 1, -1);
		// cout << fibTab(n, dp) << endl;
		cout << fib(n) << endl;
	}
}