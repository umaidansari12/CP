#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maximumEnergyBrute(vector<int>& energy, int k) {
		int max_energy = -1001;
		int _size = energy.size();
		for (int i = 0; i < _size - k; i++) {
			int _energy = -1001;
			cout << i << "->";
			for (int j = i; j < _size; j = j + k) {
				if (_energy == -1001)
					_energy = 0;
				_energy += (energy[j]);
				cout << _energy << ",";
			}
			cout << endl;
			max_energy = max(max_energy, _energy);
		}
		return max_energy;
		/*
		int max_energy = INT_MIN;
		int _size = energy.size();
		for (int i = 0; i < k; i++) {
			for (int j = _size-1-i, _energy=0; j >= 0; j = j - k) {
				_energy += (energy[j]);
		        max_energy = max(max_energy, _energy);
			}
		}
		return max_energy;

		*/
	}
	int maximumEnergyOptimal(vector<int>&energy, int k) {
		int n = energy.size();
		// every index will be touched only once, so calculating energy from n+k(last) ....... n(start)
		for (int j = n - k - 1; j >= 0; j--) {
			// calculating energy on current index
			energy[j] += energy[j + k];
		}

		int ans = -1001;
		for (int i = 0; i < n; i++) {
			ans = max(ans, energy[i]);
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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob = Solution();
		cout << ob.maximumEnergyOptimal(a, k) << endl;
	}
}