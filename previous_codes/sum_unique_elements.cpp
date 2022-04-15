#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int SumUniqueElements(int *arr, int length) {
	unordered_map<int, int> m;
	for (int i = 0; i < length; i++) {
		m[arr[i]]++;
	}
	int sum = 0;
	for (int i = 0; i < length; i++) {
		if (m[arr[i]] == 1)
			sum += arr[i];
	}
	return sum;
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
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << SumUniqueElements(a, n) << endl;
	}


	return 0;
}