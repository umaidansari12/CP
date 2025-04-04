#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
		int n, maxFreq = 0;
		cin >> n;
		unordered_map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int ele;
			cin >> ele;
			cnt[ele]++;
			if (maxFreq < cnt[ele]) {
				maxFreq = cnt[ele];
			}
		}

		cout << n - maxFreq << "\n";
	}
	return 0;
}
