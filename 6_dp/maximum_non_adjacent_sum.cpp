#include <bits/stdc++.h>

using namespace std;

// every index signifies whichever is the maximum sum when you pick elements from index 0 to index


// TC - roughly O(2^n) - trying all possible options and every index has 2 options either pick or non pick
// SC - O(N) Stack Space

void maximum_non_adjacent_sum(vector<int> &arr, int index, int sum, int &answer) {
	if (index < 0) {
		answer = max(answer, sum);
		return;
	}

	// pick
	maximum_non_adjacent_sum(arr, index - 2, sum + arr[index], answer);

	// non - pick
	maximum_non_adjacent_sum(arr, index - 1, sum, answer);
}

// TC - roughly O(2^n) - trying all possible options and every index has 2 options either pick or non pick
// SC - O(N) Stack Space

int maximum_non_adjacent_sum(vector<int> &arr, int index) {
	// we've picked index 0 and it is for sure that we're not gonna pick it's adjacent
	if (index == 0) {
		return arr[index];
	}
	// we've not picked index 0 and that's why we're skipping 0 since we must've picked 1
	if (index < 0) {
		return 0;
	}

	// we've picked the current index then we can't pick it's adjacent, so skipping it
	int pick = arr[index] + maximum_non_adjacent_sum(arr, index - 2);

	// we've not picked the current index then we can pick it's adjacent element
	int non_pick = maximum_non_adjacent_sum(arr, index - 1);

	return max(pick, non_pick);
}

// TC - roughly O(2^n) - trying all possible options and every index has 2 options either pick or non pick
// SC - O(N) Stack Space

int maximum_non_adjacent_sum(vector<int> &arr, int index, int sum) {
	if (index < 0) {
		return sum;
	}

	// pick
	int pick = maximum_non_adjacent_sum(arr, index - 2, sum + arr[index]);

	// non - pick
	int non_pick = maximum_non_adjacent_sum(arr, index - 1, sum);

	return max(pick, non_pick);
}

// TC - roughly O(n) - overlapping subproblems removed, each state will be calculated once
// SC - O(N) Stack Space + O(N) DP Array

int maximum_non_adjacent_sum_memo(vector<int> &arr, int index, int sum, vector<int> &dp) {
	if (index < 0)
		return sum;
	if (dp[index] != INT_MIN) {
		return dp[index];
	}
	int pick = maximum_non_adjacent_sum_memo(arr, index - 2, sum + arr[index], dp);
	int non_pick = maximum_non_adjacent_sum_memo(arr, index - 1, sum, dp);

	return dp[index] = max(pick, non_pick);
}

// TC - roughly O(n) - overlapping subproblems removed, each state will be calculated once
// SC - O(N) Stack Space + O(N) DP Array

int maximum_non_adjacent_sum_memo(vector<int> &arr, int index, vector<int> &dp) {
	if (index == 0)
		return arr[index];
	if (index < 0)
		return 0;
	if (dp[index] != INT_MIN) {
		return dp[index];
	}
	int pick = arr[index] + maximum_non_adjacent_sum_memo(arr, index - 2, dp);
	int non_pick = maximum_non_adjacent_sum_memo(arr, index - 1, dp);

	return dp[index] = max(pick, non_pick);
}

// TC - roughly O(n) - overlapping subproblems removed, each state will be calculated once
// SC - O(N) DP Array

int maximum_non_adjacent_sum_tabu(vector<int> &arr, int n) {
	vector<int> dp(n, 0);
	// Two cases arises, if the size of array is of only 1 element, then picking index 0 will give maximum results
	// If we're picking then we need to include this into our result if not we can just ignore
	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		// if we pick this element should be included in the result
		int pick = arr[i];
		if (i > 1)
			// if current_index greater than 1, that means there more than 2 elements and we can pick the element which is next to adjacent of current element
			pick += dp[i - 2];
		// in non pick case we straight away ignoring current element and picking it's adjacent value, whatever maximum stored there, since we started building one by one taking out max
		int non_pick = dp[i - 1];
		dp[i] = max(pick, non_pick);
		// cout << i << ":" << pick << ":" << non_pick << ":" << dp[i] << endl;
	}
	return dp[n - 1];
}

// TC - roughly O(n) - overlapping subproblems removed, each state will be calculated once
// SC - O(1)

int maximum_non_adjacent_sum_space_optimized_v1(vector<int> &arr, int n) {
	int cur = arr[0], prev = arr[0], second_prev = 0;
	for (int i = 1; i < n; i++) {
		int pick = arr[i];
		if (i > 1)
			pick += second_prev;
		int non_pick = prev;
		cur = max(pick, non_pick);
		second_prev = prev;
		prev = cur;
	}
	return cur;
}

int maximum_non_adjacent_sum_space_optimized(vector<int> &arr, int n) {
	int cur = arr[0], prev = arr[0], second_prev = 0;
	for (int i = 1; i < n; i++) {
		cur = max(prev, second_prev + arr[i]);
		second_prev = prev;
		prev = cur;
	}
	return cur;
}



int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n, 0), dp(n, INT_MIN);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int answer = 0;
		maximum_non_adjacent_sum(arr, n - 1, 0, answer);
		cout << answer << endl;
		cout << maximum_non_adjacent_sum(arr, n - 1) << endl;
		cout << maximum_non_adjacent_sum(arr, n - 1, 0) << endl;
		cout << maximum_non_adjacent_sum_memo(arr, n - 1, 0, dp) << endl;
		dp = vector<int> (n, INT_MIN);
		cout << maximum_non_adjacent_sum_memo(arr, n - 1, dp) << endl;
		cout << maximum_non_adjacent_sum_tabu(arr, n) << endl;
		cout << maximum_non_adjacent_sum_space_optimized(arr, n) << endl;
		cout << maximum_non_adjacent_sum_space_optimized_v1(arr, n) << endl;

	}
}

/*
4
3
1 2 4
4
2 1 4 9
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9

5
5
5
5
5
5
5
5
11
11
11
11
11
11
11
11
8
8
8
8
8
8
8
8
24
24
24
24
24
24
24
24


*/