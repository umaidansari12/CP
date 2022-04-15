#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int m, h;
		cin >> m >> h;
		h = h * h;
		int res = m / h;
		if (res <= 18)
			cout << 1 << endl;
		else if (res >= 19 && res <= 24)
			cout << 2 << endl;
		else if (res >= 25 && res <= 29)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}


	return 0;
}