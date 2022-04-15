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
		int a, b;
		cin >> a >> b;
		if (a == 0 or b == 0) {
			if (a == 0)
				cout << "Liquid\n";
			else if (b == 0)
				cout << "Solid\n";
		}
		else if (a > 0 and b > 0)
			cout << "Solution\n";
	}

	return 0;
}