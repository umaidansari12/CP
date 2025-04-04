#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int n = nums.size(), ans = 0;
		for (int i = 0; i < n; i++) {
			int count_odd = 0;
			for (int j = i; j < n; j++) {
				if (nums[j] % 2 != 0) {
					count_odd++;
				}
				if (count_odd == k) {
					ans++;
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int n = nums.size(), ans = 0, sum = 0;
		unordered_map<int, int> hash_map;
		for (int right = 0; right < n; right++) {
			sum += (nums[right] % 2);
			if (sum == k)
				ans++;
			if (hash_map.find(sum - k) != hash_map.end()) {
				ans += hash_map[sum - k];
			}
			hash_map[sum]++;
		}
		return ans;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob = Solution();
		cout << ob.numberOfSubarrays(a, k) << endl;
	}
}