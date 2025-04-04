#include <bits/stdc++.h>

using namespace std;

long makePowerNonDecreasing(vector<int> power) {
	long int sum = 0;
	int _size = power.size();
	for (int i = 0; i < _size; i++) {
		if (i != _size - 1 and (power[i + 1] + sum) < (power[i] + sum)) {
			sum += (power[i] - power[i + 1]);
		}
	}
	return sum;
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << makePowerNonDecreasing(arr) << endl;
	}
}


/*
I ->

3
3
3 2 1
4
3 5 2 3
5
3 4 1 6 2

O->
2
3
7
*/