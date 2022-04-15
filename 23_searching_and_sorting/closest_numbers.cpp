#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void closestNumbers(vector<int> numbers) {

	int n = numbers.size(), min_diff = INT_MAX;
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < n - 1; i++) {
		min_diff = min(numbers[i + 1] - numbers[i], min_diff);
	}
	for (int i = 0; i < n - 1; i++) {
		if (abs(numbers[i + 1] - numbers[i]) == min_diff) {
			cout << numbers[i] << " " << numbers[i + 1] << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(numbers[j] - numbers[i]) == min_diff) {
				cout << numbers[i] << " " << numbers[j] << endl;
			}
		}
	}
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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		closestNumbers(a);
	}


	return 0;
}