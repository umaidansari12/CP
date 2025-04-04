#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	long long int gcd(int a, int b) {
		if (a == b)
			return a;
		else if (a > b)
			return gcd(a - b, b);
		else
			return gcd(a, b - a);
	}
	long long maxScore(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		if (n == 1)
			return nums[0] * nums[0];
		long long int result_gcd_excluding_first = nums[1], result_gcd_including_first = nums[0], product = 1;
		for (int i = 0; i < n; i++) {
			product *= nums[i];
			if (i != 0)
				result_gcd_excluding_first = gcd(result_gcd_excluding_first, nums[i]);
			result_gcd_including_first = gcd(result_gcd_including_first, nums[i]);
		}

		cout << result_gcd_including_first << "-" << result_gcd_excluding_first << "-" << product << "-" << product / nums[0] << endl;

		return max(result_gcd_including_first * (product / result_gcd_including_first), result_gcd_excluding_first * ((product / nums[0]) / result_gcd_excluding_first));
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> a(N, 0);
		for (int i = 0; i < N; i++)
			cin >> a[i];
		Solution ob;
		cout << ob.maxScore(a) << endl;
	}
}

/*
Input -
3
4
2 4 8 16
5
1 2 3 4 5
1
3
*/