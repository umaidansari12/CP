#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int num;
		cin >> num;
		double root = cbrt(num);
		long long int intRoot = (int)root;
		if ((intRoot * intRoot * intRoot) == num)
			count++;
	}
	cout << count << endl;

	return 0;
}