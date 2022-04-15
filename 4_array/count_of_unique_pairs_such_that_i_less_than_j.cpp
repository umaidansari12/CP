#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Find total number of (i,j) pairs in array such that i<j and a[i]>a[j].
//count of inversions in the array

int countUniquePairs(int a[], int n) {
	set<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				s.insert({a[i], a[j]});
		}
	}
	return s.size();
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << countUniquePairs(a, n) << endl;
	}


	return 0;
}