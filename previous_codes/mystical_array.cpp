#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int MysticalArray(int k, int arr[], int n) {
	if (n == 0)
		return -1;
	int steps = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] >= arr[i + 1]) {
			while (arr[i] >= arr[i + 1]) {
				arr[i + 1] += k;
				steps++;
			}
		}
	}
	return steps;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << MysticalArray(k, a, n) << endl;
	}





	return 0;
}