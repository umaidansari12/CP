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
		int xA, xB, xC;
		cin >> xA >> xB >> xC;
		if (xA > 50)
			cout << "A\n";
		else if (xB > 50)
			cout << "B\n";
		else if (xC > 50)
			cout << "C\n";
		else
			cout << "NOTA\n";
	}

	return 0;
}