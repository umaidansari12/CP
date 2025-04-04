#include<bits/stdc++.h>

using namespace std;

void printAllSubsequence(vector<int> a, vector<int> &ds, int idx, int n, int s, int sum) {
	if (s > sum)
		return ;
	if (idx == n) {
		if (s == sum) {
			for (auto i : ds) {
				cout << i << " ";
			}
			cout << endl;
		}
		return;
	}

	// take or pick the particular index into the subsequence
	ds.push_back(a[idx]);
	s += a[idx];
	printAllSubsequence(a, ds, idx + 1, n, s, sum);
	ds.pop_back();
	s -= a[idx];
	// not pick or not take condition, this element is not added to your subsequence
	printAllSubsequence(a, ds, idx + 1, n, s, sum);

}

int main() {
	int n, sum;
	cin >> n >> sum;

	vector<int> a(n), ds;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	printAllSubsequence(a, ds, 0, n, 0, sum);
}

// TC - 2^n * n
// _ _ _ for every index you've 2 options so total options will be 2^n, and n is required to print the array
// SC - O(n)
// recursion tree/stack is atmost n level deep
