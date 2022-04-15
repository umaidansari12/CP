#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int averageFlex(int a[], int n) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int lesser = 0 , greater = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] <= a[i]) {
				lesser++;
			}
			else {
				greater++;
			}

		}
		if (lesser > greater) {
			answer++;
		}
	}

	return answer;
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
		cout << averageFlex(a, n) << endl;
	}


	return 0;
}