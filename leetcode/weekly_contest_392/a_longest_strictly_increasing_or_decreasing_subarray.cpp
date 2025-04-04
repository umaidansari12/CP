#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int longestMonotonicSubarray(vector<int>& arr) {
		int inc = 1, dec = 1, n = arr.size();
		for (int i = 0; i < n; i++) {
			int len = 1;
			for (int j = 0; (i + j + 1) < n; j++) {
				if (arr[i + j] < arr[(i + j + 1)]) {
					len = len + 1;
				}
				else
					break;
			}
			inc = max(inc, len);
		}
		for (int i = 0; i < n; i++) {
			int len = 1;
			for (int j = 0; (i + j + 1) < n; j++) {
				if (arr[i + j] > arr[(i + j + 1)]) {
					len = len + 1;
				}
				else
					break;
			}
			dec = max(dec, len);
			// cout << i << ":" << len << endl;
		}
		// cout << inc << "-" << dec << endl;
		return max(inc, dec);
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
		cout << ob.longestMonotonicSubarray(a) << endl;

	}
}

/*
I:
3
5
1 4 3 3 2
4
3 3 3 3
3
3 2 1

O:
2
1
3

*/