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
		int countOne = 0, countZero = 0, x;
		for (int i = 0; i < 7; i++) {
			cin >> x;
			if (x == 1)
				countOne += 1;
			else
				countZero += 1;
		}
		if (countOne > countZero)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}