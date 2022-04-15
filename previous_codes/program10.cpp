#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n, x, y, slope;
	cin >> n;
	map<int, int> m;
	vector<pair<int, int> > a;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a.push_back({x, y});
	}
	x = a[0].first;
	y = a[0].second;
	for (int j = 1; j < n; j++) {
		int x1 = a[j].first;
		int y1 = a[j].second;
		slope = (y1 - y) / (x1 - x);
		m[slope]++;
	}
	if (m[slope] == (n - 1)) {
		cout << slope << "x-" << slope << "y=0\n";
	}
	else
		cout << 0 << endl;

	return 0;
}