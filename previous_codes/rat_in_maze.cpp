#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(vector<vector<int>>&maze, int x, int y, int n)
{
	if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1)
		return true;
	return false;
}

bool rat_in_maze(vector<vector<int>>&maze, int x, int y, int n, vector<vector<int>>&res)
{
	if (x == n - 1  && y == n - 1 && maze[x][y] == 1)
	{
		res[x][y] = 1;
		return true;
	}
	if (isSafe(maze, x, y, n))
	{
		res[x][y] = 1;
		if (rat_in_maze(maze, x + 1, y, n, res))
			return true;
		if (rat_in_maze(maze, x , y + 1, n, res))
			return true;
		res[x][y] = 0;
		//return false;
	}
	return false;

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
		vector<vector<int>> res(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> maze[i][j];
		if (rat_in_maze(maze, 0, 0, n, res))
		{
			for (vector<int> r : res)
			{
				for (int i : r)
					cout << i << " ";
				cout << endl;
			}
			//vector<string> r;
			int x = 0, y = 0;
			while (1)
			{
				if (x == n || y == n) break;
				if (res[x + 1][y] == 1)
				{
					cout << "D";
					//r.push_back("R");
					x++;
				}
				else if (res[x][y + 1] == 1)
				{
					cout << "R";
					//r.push_back("D");
					y++;
				}
			}
			/*for (string i : r)
				cout << i;
			cout << endl;*/
		}
		else
			cout << -1 << endl;
	}


	return 0;
}