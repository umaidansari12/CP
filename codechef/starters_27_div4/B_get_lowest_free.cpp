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
		int a, b, c;
		cin >> a >> b >> c;

		int sum = a + b + c;
		int _min = min(a, min(b, c));

		cout << sum - _min << endl;
	}

	return 0;
}