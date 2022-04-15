#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

		double ans = 0.143 * n;

		ans = pow(ans, n);

		int _floor = floor(ans);

		if ((ans - _floor) < 0.5)
			cout << _floor << endl;
		else
			cout << (int)(_floor + 1) << endl;


	}


	return 0;
}