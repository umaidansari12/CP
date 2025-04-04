#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int min_jumps(vector<int> &nums, int _size, int index, int jumps) {
		if (index >= _size - 1)
			return jumps;
		int _min = INT_MAX;
		// cout << index << endl;
		for (int i = 1; i <= nums[index]; i++) {
			int ans;
			if ((index + i) <= _size and nums[index + i] != 0) {
				ans = min_jumps(nums, _size, index + i, jumps + 1);
				_min = min(_min, ans);
			}
		}
		// cout << index << ":-:" << _min << endl;
		if (_min == INT_MAX)
			return jumps;
		return _min;
	}
	int jump(vector<int>& nums) {
		int _size = nums.size();
		return min_jumps(nums, _size, 0, 0);
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		Solution ob = Solution();
		cout << ob.jump(a) << endl;
		cout << "--------\n";
	}
}