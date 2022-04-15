#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1000000007

int solve(vector<vector<int>> &dp, int i, int j, int n, int m)
{
	if (i == n - 1 && j == m - 1)
		return 1;
	if (i >= n || j >= m)
		return 0;
	//if (dp[i][j] != -1)
	//	return dp[i][j];
	return dp[i][j] = solve(dp, i + 1, j, n, m) + solve(dp, i, j + 1, n, m);
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
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> maze(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			maze[x - 1][y - 1] = -1;
		}
		cout << solve(maze, 0, 0, n, m) % mod << endl;


	}

	return 0;
}/*#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1000000007

bool isSafe(vector<vector<int>>&maze, int x, int y, int n, int m, vector<vector<bool>>&visited)
{
	if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == false && maze[x][y] == 0)
		return true;
	return false;
}

void solve(vector<vector<int>>&maze, int x, int y, int n, int m, vector<vector<bool>>&visited, int &count)
{
	if (x == n - 1 && y == m - 1 && maze[x][y] == 0)
	{
		count++;
		return;
	}
	visited[x][y] = true;
	if (isSafe(maze, x + 1, y, n, m, visited))
	{
		solve(maze, x + 1, y, n, m, visited, count);
	}
	if (isSafe(maze, x, y + 1, n, m, visited))
	{
		solve(maze, x, y + 1, n, m, visited, count);
	}
	visited[x][y] = false;
	return;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> maze(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			maze[x - 1][y - 1] = -1;
		}
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << maze[i][j] << " ";
			cout << endl;
		}
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		int count = 0;
		solve(maze, 0, 0, n, m, visited, count);
		count %= mod;
		cout << count << endl;
	}

	return 0;
}*/