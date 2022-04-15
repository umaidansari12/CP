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
		int x, y, xr, yr, d;
		int dx, dy, sd;
		cin >> x >> y >> xr >> yr >> d;
		dx = x / xr;
		dy = y / yr;
		//cout << dx << " " << dy << endl;
		sd = min(dx,  dy);
		if (sd < d)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}