#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printSolution(vector<vector<int>>& board, int n)
{
	vector <int> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j])
				r.push_back(j + 1);
		}
	}
	cout << "[";
	for (auto i : r)
	{
		cout << i << " ";
	}
	cout << "] ";
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
	for (int i = 0; i < col; i++)
	{
		if (board[row][i])
			return false;
	}
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return false;
	}
	for (int i = row, j = col; j >= 0 && i < n; i++, j--)
	{
		if (board[i][j])
			return false;
	}
	return true;
}
bool solve_NQUtil(vector<vector<int>>& board, int col, int n)
{
	if (col == n)
	{
		printSolution(board, n);
		return true;
	}
	bool res = false;
	for (int i = 0; i < n; i++)
	{
		if (isSafe(board, i, col, n))
		{
			board[i][col] = 1;
			res = solve_NQUtil(board, col + 1, n) || res;
			board[i][col] = 0;
		}

	}
	return res;
}
void solve_NQ(int n)
{
	vector<vector<int>> board(n, vector<int> (n, 0));

	if (solve_NQUtil(board, 0, n) == false)
	{
		cout << "Solution Does'nt Exist\n";
	}
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
		int n;
		cin >> n;
		solve_NQ(n);
		cout << endl;
	}



	return 0;
}