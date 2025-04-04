#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minimumSum(vector<int>& nums) {
		int ans = -1;
		int minimum_sum = INT_MAX;
		int _size = nums.size();
		for (int i = 0; i < _size; i++) {
			for (int j = i + 1; j < _size; j++) {
				for (int k = j + 1; k < _size; k++) {
					if (nums[i] < nums[j] and nums[k] < nums[j]) {
						minimum_sum = min(minimum_sum, nums[i] + nums[j] + nums[k]);
					}
				}
			}
		}
		if (minimum_sum == INT_MAX)
			return ans;
		return minimum_sum;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob = Solution();
		cout << ob.minimumSum(a) << endl;
	}
}