#include<bits/stdc++.h>

using namespace std;

void printAllSubsequence(vector<int> a, vector<int> &ds, int idx, int n) {
	if (idx == n) {
		for (auto i : ds) {
			cout << i << " ";
		}
		if (ds.size() == 0) {
			cout << "{}";
		}
		cout << endl;
		return;
	}

	// take or pick the particular index into the subsequence
	ds.push_back(a[idx]);
	printAllSubsequence(a, ds, idx + 1, n);
	ds.pop_back();
	// not pick or not take condition, this element is not added to your subsequence
	printAllSubsequence(a, ds, idx + 1, n);

}

int main() {
	int n;
	cin >> n;

	vector<int> a(n), ds;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	printAllSubsequence(a, ds, 0, n);
}

// TC - 2^n * n
// _ _ _ for every index you've 2 options so total options will be 2^n, and n is required to print the array
// SC - O(n)
// recursion tree/stack is atmost n level deep
