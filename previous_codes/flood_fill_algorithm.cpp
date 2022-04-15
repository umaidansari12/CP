#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(vector<vector<int>>&a, int x, int y, int n, int m, int color)
{
	if (x == -1 || x == n || y == -1 || y == m || a[x][y] != color)
		return false;
	return true;
}

void flood(vector<vector<int>>&a, int n, int m, int x, int y, int color, int k)
{
	if (x == -1 || x == n || y == -1 || y == m || a[x][y] != color)
		return;
	/*if (x == n - 1 && y == m - 1)
		return;*/
	a[x][y] = k;
	if (isSafe(a, x + 1, y, n, m, color))
	{
		flood(a, n, m, x + 1, y, color, k);
	}
	if (isSafe(a, x , y - 1, n, m, color))
	{
		flood(a, n, m, x, y - 1, color, k);
	}
	if (isSafe(a, x, y + 1, n, m, color))
	{
		flood(a, n, m, x, y + 1, color, k);
	}
	if (isSafe(a, x - 1, y, n, m, color))
	{
		flood(a, n, m, x - 1, y, color, k);
	}

	return ;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, x, y, k;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		cin >> x >> y >> k;
		int color = a[x][y];
		flood(a, n, m, x, y, color, k);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cout << a[i][j] << " ";

		cout << endl;

	}


	return 0;
}

class Solution {
public:
	void solve(vector<vector<int>>&a, int x, int y, int n, int m, int c, int k)
	{
		if (x < 0 || x >= n || y < 0 || y >= m)
			return;
		if (a[x][y] != c)
			return;
		if (a[x][y] == k)
			return;
		a[x][y] = k;
		solve(a, x + 1, y, n, m, c, k);
		solve(a, x - 1, y, n, m, c, k);
		solve(a, x, y - 1, n, m, c, k);
		solve(a, x, y + 1, n, m, c, k);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int color = image[sr][sc], n = image.size(), m = image[0].size();
		solve(image, sr, sc, n, m, color, newColor);
		return image;
	}
};