#include <bits/stdc++.h>

using namespace std;

int countUniquePairsBrute(int a[], int n) {
	set<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			s.insert({a[i], a[j]});
		}
	}
	return s.size();
}

int countUniquePairs(int a[], int n) {
	set<int> visited1, visited2;
	int unique[n] = {0};
	unique[n - 1] = 0;
	int count = 0;
	for (int i = n - 1; i > 0; i--) {
		auto pos = visited1.find(a[i]);
		if (pos != visited1.end()) {
			unique[i - 1] = count;
		}
		else
			unique[i - 1] = ++count;
		visited1.insert(a[i]);
	}
	int answer = 0;
	for (int i = 0; i < n - 1; i++) {
		auto pos = visited2.find(a[i]);
		if (pos != visited2.end()) {
			continue;
		}
		answer += unique[i];
		visited2.insert(a[i]);
	}
	return answer;

}

int main() {
	ios_base::sync_with_stdio(false);
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