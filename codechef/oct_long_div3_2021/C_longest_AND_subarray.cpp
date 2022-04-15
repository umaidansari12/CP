#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int countBits(long long int number) {
	return (long long int)log2(number) + 1;
}

long long int count_bits(long long int number) {
	long long int bits = 0;
	while (number) {
		bits++;
		number /= 2;
	}
	return bits;
}

long long int solveOptimal(long long int n) {
	if (n == 1)
		return 1;
	long long int bits = countBits(n);
	long long int ans = pow(2, bits - 1);
	long long int res = n - ans + 1;
	if (n == res) {
		return ans / 2;
	}
	return max(ans / 2, res); //n - pow(2, bits - 1) + 1;
}



long long int solve(long long int n) {
	long long int _and = 1, a[n] = {0}, len = 0, maxLen = 1;
	for (int i = 0; i < n; i++)
	{
		_and &= (i + 1);
		if (_and == 0) {
			a[i] = 0;
			_and = (i + 2);
		}
		else {
			a[i] = _and;
		}
	}

	for (int i = 0; i < n; i++)
	{
		//cout << a[i] << " ";
		if (a[i] == 0) {
			maxLen = max(maxLen, len);
			len = 1;
		}
		else
		{
			len++;
		}
	}
	//cout << endl;
	maxLen = max(maxLen, len);

	return maxLen;
}

long long int solveBrute(long long int n) {

	int a[n] = {0};
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int max_and = 0, i = 0, j = 0, _and = a[0];
	// for (int j = 0; j < n; j++)
	// {
	// 	_and &= a[j];
	// 	while (_and != 0) {
	// 		_and &= a[i];
	// 		i++;
	// 	}
	// 	max_and = max(max_and, j - i + 1);

	// }
	for (int i = 0; i < n; i++) {
		int _and = a[i];
		for (int j = i; j < n; j++) {
			_and = _and & a[j];
			if (_and > 0)
				max_and = max(max_and, j - i + 1);
		}
	}
	//cout << max_and << endl;
	return max_and;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long int n;
		cin >> n;
		cout << solveOptimal(n) << endl;
		//cout << solve(n) << " " << solveBrute(n) << " " << solveOptimal(n) << endl;

	}
	return 0;
}