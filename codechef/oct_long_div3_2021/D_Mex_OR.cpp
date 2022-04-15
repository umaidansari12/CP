#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solveBrute() {
	long long int x, _or = 0, ans = -1;
	cin >> x;
	bool flag = false;
	for (long long int i = 0; i <= x; i++) {
		if ((_or | i) <= x) {
			_or |= i;
		}
		else
		{
			//	cout << i << endl;
			flag = true;
			ans = i;
			break;
		}
	}
	if (!flag)
		cout << x + 1 << endl;
	else
		cout << ans << endl;
}

long long int computeOR(long long int x) {
	long long int _or = 0;
	// for (int i = 1; i <= x; i++) {
	// 	_or |= i;
	// }
	for (int i = 1; i <= x; i *= 2) {
		_or |= i;
	}
	return _or;
}

void solveOptimal() {
	long long int x;
	cin >> x;
	if (x == 0) {
		cout << 1 << endl;
		return;
	}
	if (x == 1 or x == 2) {
		cout << 2 << endl;
		return;
	}
	long long int n2pow = (long long int)log2(x);
	long long int nearP = (long long int)pow(2, n2pow);
	long long int nearPright = (long long int)pow(2, n2pow + 1);
	long long int rightOr = nearPright - 1;
	if (x == rightOr) {
		cout << nearPright << endl;
	}
	else {
		cout << nearP << endl;
	}

}

void solveBinarySearch() {
	long long int x;
	cin >> x;
	long long int low = 0, high = x;
	while (low <= high) {
		long long int mid = (low + high) / 2;
		long long int OR = computeOR(mid);
		if (OR <= x) {
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << low << endl;

}



int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		//solveBinarySearch();
		solveOptimal();
	}



	return 0;
}