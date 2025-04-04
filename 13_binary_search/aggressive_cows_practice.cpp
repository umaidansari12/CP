#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool can_place_c_cows_at_d_distance(vector<int> &stalls, int cows, int distance) {
		int cows_placed = 1, last_placed = stalls[0], n = stalls.size();
		for (int i = 1; i < n; i++) {
			if (stalls[i] - last_placed >= distance) {
				cows_placed++;
				last_placed = stalls[i];
			}
			// if (cows_placed == cows)
			if (cows_placed >= cows)
				return true;
		}
		return false;
	}
	int aggressive_cows(vector<int> &stalls, int cows) {
		int stalls_size = stalls.size();
		sort(stalls.begin(), stalls.end());
		int low = 1;
		// int _min = *min_element(stalls.begin(), stalls.end());
		// int _max = *max_element(stalls.begin(), stalls.end());
		int _min = stalls[0];
		int _max = stalls[stalls_size - 1];
		int high = _max - _min;
		// for (int distance = low; distance <= high; distance++) {
		// 	if (can_place_c_cows_at_d_distance(stalls, cows, distance)) {
		// 		continue;
		// 	}
		// 	else {
		// 		return distance - 1;
		// 	}
		// }
		while (low <= high) {
			int mid = (low + high) / 2;
			if (can_place_c_cows_at_d_distance(stalls, cows, mid)) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		// return low-1;
		return high;
	}
};


int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, c;
		cin >> n >> c;
		vector <int> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob = Solution();
		cout << ob.aggressive_cows(a, c) << endl;
	}
}