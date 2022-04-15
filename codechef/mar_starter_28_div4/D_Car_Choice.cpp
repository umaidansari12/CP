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
		float x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		float a = y1 / x1;
		float b = y2 / x2;

		if (a == b) {
			cout << "0\n";
		}
		else if (a > b) {
			cout << "1\n";
		}
		else if (a < b) {
			cout << "-1\n";
		}
	}


	return 0;
}