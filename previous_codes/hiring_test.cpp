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
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			int f = count(s.begin(), s.end(), 'F');
			int p = count(s.begin(), s.end(), 'P');
			if (f >= x)
				cout << 1;
			else if (f == x - 1 && p >= y)
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}

	return 0;
}