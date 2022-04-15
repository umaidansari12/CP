#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		x -= y;
		y /= 2;

		cout << (x + y) << endl;
	}

	return 0;
}