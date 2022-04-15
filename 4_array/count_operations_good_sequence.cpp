#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countOperations(int *A, int N) {
	int count = 0;
	for (int i = 0; i < (N - 2); i++) {
		if (A[i] != A[i + 2]) {
			A[i + 2] = A[i];
			count++;
		}
	}

	return count;

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

		cout << countOperations(a, n) << endl;
	}


	return 0;
}