#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool usedInCol(vector<vector<int>>&board, int col, int num)
{
	for (int row = 0; row < 9; row++)
		if (board[row][col] == num)
			return true;
	return false;
}

bool usedInRow(vector<vector<int>>&board, int row, int num)
{
	for (int col = 0; col < 9; col++)
		if (board[row][col] == num)
			return true;
	return false;
}

bool usedInBox(vector<vector<int>>&board, int startrow, int startcol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row + startrow][col + startcol] == num)
				return true;
	return false;
}

bool findZero(vector<vector<int>>&board, int& row, int& col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (board[row][col] == 0)
				return true;

	return false;
}
bool isSafe(vector<vector<int>>&board, int row, int col, int num)
{
	return !usedInCol(board, col, num) && !usedInRow(board, row, num) && !usedInBox(board, row - row % 3, col - col % 3, num) && board[row][col] == 0;
}

bool solveSudoku(vector<vector<int>>&board)
{
	int row, col;
	if (!findZero(board, row, col))
		return true;
	for (int num = 0; num <= 9; num++)
	{
		if (isSafe(board, row, col, num))
		{
			board[row][col] = num;
			if (solveSudoku(board))
				return true;
			board[row][col] = 0;
		}
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
		vector<vector<int>> board(9, vector<int> (9, 0));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cin >> board[i][j];
		}
		if (solveSudoku(board))
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					cout << board[i][j] << " ";
				cout << endl;
			}

		}
		else
		{
			cout << "No Solution Exists!\n";
		}
	}


	return 0;
}

class Solution {
public:
	bool findZero(vector<vector<char>>& board, int& row, int& col)
	{
		for (row = 0; row < 9; row++)
			for (col = 0; col < 9; col++)
				if (board[row][col] == '.')
					return true;
		return false;
	}

	bool usedInRow(vector<vector<char>>& board, int &row, int num)
	{
		char a = num + '0';
		for (int col = 0; col < 9; col++)
			if (board[row][col] == a)
				return true;
		return false;
	}
	bool usedInCol(vector<vector<char>>& board, int &col, int num)
	{
		char a = num + '0';
		for (int row = 0; row < 9; row++)
			if (board[row][col] == a)
				return true;
		return false;
	}
	bool usedInBox(vector<vector<char>>& board, int srow, int scol, int num)
	{
		char a = num + '0';
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				if (board[row + srow][col + scol] == a)
					return true;
		return false;
	}
	bool isSafe(vector<vector<char>>& board, int& row, int& col, int num)
	{
		return !usedInRow(board, row, num) && !usedInCol(board, col, num) && !usedInBox(board, row - row % 3, col - col % 3, num) && board[row][col] == '.';
	}
	bool solve(vector<vector<char>>&board)
	{
		int row, col;
		if (!findZero(board, row, col))
			return true;
		for (int num = 1; num <= 9; num++)
		{
			if (isSafe(board, row, col, num))
			{
				char a = num + '0';
				board[row][col] = a;
				if (solve(board))
					return true;
				board[row][col] = '.';
			}
		}
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
};

bool isSafe(int grid[N][N],  int n, int i, int j)
{
	for (int k = 0; k < N; k++)
	{
		if (grid[i][k] == n || grid[k][j] == n)
		{
			return false;
		}
	}

	int s = sqrt(N);
	int rs = i - i % s;
	int cs = j - j % s;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (grid[i + rs][j + cs] == n) {
				return false;
			}
		}
	}

	return true;
}

bool solve(int grid[N][N], int no) {
	int x = no / N;
	int y = no % N;

	if (x == N)
		return true;
	if (grid[x][y] != 0)
		return solve(grid, no + 1);

	for (int i = 1; i <= 9; i++) {
		if (isSafe(grid, i, x, y)) {
			grid[x][y] = i;
			if (solve(grid, no + 1))
				return true;
			grid[x][y] = 0;
		}
	}
	return false;
}

bool SolveSudoku(int grid[N][N])
{
	// Your code here
	return solve(grid, 0);
}

void printGrid (int grid[N][N])
{
	// Your code here
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j] << " ";
		}
	}
}
