#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void PLEBrute(int a[], int n) {
	int res[n] = {0};
	for (int i = 0; i < n; i++) {
		int ans = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (ans > a[j]) {
				ans = min(ans, a[j]);
				break;
			}
		}

		if (ans == a[i]) {
			res[i] = -1;
		}
		else
			res[i] = ans;
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

void PLE(int a[], int n) {
	// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
	stack<int> s;
	int res[n] = {0};
	for (int i = 0; i < n; i++) {
		while (!s.empty() and a[i] < a[s.top()]) {
			s.pop();
		}
		if (s.empty()) {
			res[i] = -1;
		}
		else {
			res[i] = a[s.top()];
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
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
		PLE(a, n);
		PLEBrute(a, n);
	}



	return 0;
}