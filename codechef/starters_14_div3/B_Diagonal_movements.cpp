#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

void solve(int i, int j, int x, int y, bool &f) {
	if (i == x and j == y) {
		f = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = i + dx[i];
		int ny = j + dy[i];
		solve(nx, ny, x, y, f);
	}
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		// bool f = false;
		// int x, y;
		// cin >> x >> y;
		// solve(0, 0, x, y, f);
		// if (f)
		// 	cout << "YES\n";
		// else
		// 	cout << "NO\n";
		ll x, y;
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		if ((x + y) % 2 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}