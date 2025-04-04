#include<bits/stdc++.h>

using namespace std;

int printSubsequence(vector<int> a, int idx, int n, int s, int sum) {
	// can only be done if the array contains only positive
	if (s > sum)
		return 0;
	if (idx == n) {
		if (s == sum) {
			return 1;
		}
		return 0;
	}

	// take or pick the particular index into the subsequence
	s += a[idx];
	int left = printSubsequence(a, idx + 1, n, s, sum);
	s -= a[idx];
	// not pick or not take condition, this element is not added to your subsequence
	int right = printSubsequence(a, idx + 1, n, s, sum);
	return left + right;
}

int main() {
	int n, sum;
	cin >> n >> sum;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << printSubsequence(a, 0, n, 0, sum) << endl;
}

// TC - 2^n * n
// _ _ _ for every index you've 2 options so total options will be 2^n, and n is required to print the array
// SC - O(n)
// recursion tree/stack is atmost n level deep
