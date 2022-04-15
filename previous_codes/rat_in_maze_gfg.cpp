#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(vector<vector<int>>&maze, int x, int y, int n, vector<vector<bool>>&visited)
{
	if (x == -1 || x == n || y == -1 || y == n || visited[x][y] || maze[x][y] == 0)
		return false;
	return true;
}

void rat_in_maze(vector<vector<int>>&maze, int x, int y, int n, vector<string>&res, string s, vector<vector<bool>>&visited)
{
	if (x == -1 || x == n || y == -1 || y == n || visited[x][y] || maze[x][y] == 0)
		return;
	if (x == n - 1  && y == n - 1)
	{
		res.push_back(s);
		return ;
	}
	visited[x][y] = true;
	if (isSafe(maze, x + 1, y, n, visited))
	{
		s.push_back('D');
		rat_in_maze(maze, x + 1, y, n, res, s, visited);
		s.pop_back();
	}
	if (isSafe(maze, x, y - 1, n, visited))
	{
		s.push_back('L');
		rat_in_maze(maze, x , y - 1, n, res, s, visited);
		s.pop_back();
	}
	if (isSafe(maze, x, y + 1, n, visited))
	{
		s.push_back('R');
		rat_in_maze(maze, x, y + 1, n, res, s, visited);
		s.pop_back();
	}
	if (isSafe(maze, x - 1, y, n, visited))
	{
		s.push_back('U');
		rat_in_maze(maze, x - 1, y, n, res, s, visited);
		s.pop_back();
	}
	visited[x][y] = false;
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
		int n;
		cin >> n;
		vector<vector<int>> maze(n, vector<int>(n, 0));
		vector<string> res;
		string s;
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> maze[i][j];
		rat_in_maze(maze, 0, 0, n, res, s, visited);
		if (res.size() != 0)
		{
			//int k = 0;
			for (string r : res)
			{
				//cout << ++k << endl;
				cout << r << endl;
			}
			cout << "Done\n";
		}
		else
			cout << -1 << "\nDone\n" << endl;
	}


	return 0;
}