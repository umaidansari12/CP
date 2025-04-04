#include <bits/stdc++.h>

using namespace std;

long long int house_robber_ii(vector<int> &arr, int index) {
	// if reached at index 0, and length of array is even that means we did'nt pick the last index, since in even starting with last index we'll land at odd index
	// as we don't want both of first and last element to be contained in the answer
	if (index == 0 and arr.size() % 2 == 0)
		return arr[index];
	if (index == 0 and arr.size() % 2) {
		return 0;
	}
	if (index < 0)
		return 0;

	int pick = arr[index] + house_robber_ii(arr, index - 2);
	int non_pick = house_robber_ii(arr, index - 1);
	return max(pick, non_pick);
}

long long int house_robber_ii_space_optimized(vector<int> arr, int n) {
	if (n == 1)
		return arr[0];
	long long int cur_i = arr[0], prev_i = arr[0], second_prev = 0;
	for (int i = 1; i < n; i++) {
		long long int pick = arr[i];
		if (i > 1) {
			pick += second_prev;
		}
		long long int non_pick = prev_i;
		cur_i = max(pick, non_pick);
		second_prev = prev_i;
		prev_i = cur_i;
	}
	return cur_i;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n, 0), temp1, temp2;
		// logic here is we know both of the first and last element can't be present in the answer, so why we don't we calculate our answer by excluding first once and last once and then taking maximum of both
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (i != 0)
				temp1.push_back(arr[i]);
			if (i != n - 1)
				temp2.push_back(arr[i]);
		}


		// cout << house_robber_ii(arr, n - 1) << endl;
		int n1 = temp1.size();
		int n2 = temp2.size();
		long long int ans1 = 0, ans2 = 0, ans3 = 0;
		if (n1 > 0)
			ans1 = house_robber_ii_space_optimized(temp1, n1);
		if (n2 > 0)
			ans2 = house_robber_ii_space_optimized(temp2, n2);
		if (n == 1)
			ans3 = house_robber_ii_space_optimized(arr, n);
		cout << max(ans3, max(ans1, ans2)) << endl;
	}
}

class Solution {
public:
	int helper(int n, vector<int> &nums, vector<int>  &dp) {
		if (n == 0)
			return nums[0];
		if (n < 0)
			return 0;
		if (dp[n] != -1)
			return dp[n];
		int pick = nums[n] + helper(n - 2, nums, dp);
		int non_pick = helper(n - 1, nums, dp);
		return dp[n] = max(pick, non_pick);
	}
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		if (n == 2)
			return max(nums[0], nums[1]);
		vector<int> temp1;
		vector<int> temp2;
		vector<int> dp1(n - 1, -1);
		vector<int> dp2(n - 1, -1);
		for (int i = 0; i < n; i++) {
			if (i != 0)
				temp1.push_back(nums[i]);
			if (i != n - 1)
				temp2.push_back(nums[i]);
		}
		return max(helper(n - 2, temp1, dp1), helper(n - 2, temp2, dp2));
	}
};

/*

I :
6
1
0
3
2 3 2
4
1 3 2 1
5
1 5 1 2 6
3
2 3 5
4
1 3 2 0

O :

0
3
4
11
5
3

*/