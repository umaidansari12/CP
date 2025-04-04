#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	long long maximumHappinessSum(vector<int>& happiness, int k) {
		sort(happiness.begin(), happiness.end(), greater<int>());
		long long maximumHappinessSum = 0;
		for (int i = 0; i < k; i++) {
			maximumHappinessSum += max(happiness[i] - i, 0);
		}
		return maximumHappinessSum;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> happiness(n, 0);
		for (int i = 0; i < n; i++)
			cin >> happiness[i];
		Solution ob = Solution();
		cout << ob.maximumHappinessSum(happiness, k) << endl;
	}
}