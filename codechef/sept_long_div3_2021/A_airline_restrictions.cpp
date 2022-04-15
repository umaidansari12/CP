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
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		bool found = false;
		if ((a + b) <= d and c <= e)
			found = true;
		else if ((a + c) <= d and b <= e)
			found = true;
		else if ((b + c) <= d and a <= e)
			found = true;
		if (found)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}