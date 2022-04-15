#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void NLEBrute(int a[], int n) {
	int res[n] = {0};
	for (int i = 0; i < n; i++) {
		int ans = a[i];
		for (int j = i + 1; j < n; j++) {
			if (a[j] < ans) {
				ans = a[j];
				break;
			}
		}
		if (ans == a[i])
			res[i] = -1;
		else
			res[i] = ans;
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

void NLE(int a[], int n) {

	// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
	int res[n] = {0};
	memset(res, -1, sizeof(res));
	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() and a[s.top()] > a[i]) {
			res[s.top()] = a[i];
			s.pop();
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
		NLEBrute(a, n);
		NLE(a, n);
	}


	return 0;
}