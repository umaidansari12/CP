#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minimumSum(vector<int>& nums) {
		int ans = -1;
		int minimum_sum = INT_MAX;
		int _size = nums.size();
		vector<pair<int, int>> a;
		for (int i = 0; i < _size; i++) {
			a.push_back(make_pair(nums[i], i));
		}
		sort(a.begin(), a.end(), [](pair<int, int> &c, pair<int, int> &d) {
			return c.first < d.first;
		});
		for (int i = 0; i < _size; i++) {
			cout << a[i].first << "-" << a[i].second << endl;
		}
		for (int i = 0; i <= _size - 2; i++) {
			int ith_idx = a[i].second;
			int kth_idx = a[i + 1].second;
			int jth_idx = a[i + 2].second;
			cout << ith_idx << ":" << jth_idx << ":" << kth_idx << endl;

			if (ith_idx < jth_idx and jth_idx < kth_idx) {
				minimum_sum = min(minimum_sum, nums[ith_idx] + nums[jth_idx] + nums[kth_idx]);
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