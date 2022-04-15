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
	while (t--)
	{
		int x;
		cin >> x;
		if (x <= 15) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}

	return 0;
}