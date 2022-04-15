#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printSolution(vector<vector<int>>&board, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


bool isAttacked(int row, int col, vector<vector<int>>&board, int n)
{

	for (int i = 0; i < n; i++) {
		if ((board[row][i] == 1) && (i != col)) {
			return true;
		}

		if ((board[col][y] == 1) && (i != row)) {
			return true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ( ((i + j) == (row + col)) || ((i - j) == (row - col)) ) {
				if (((i != row) || (j != col)) && (board[i][j] == 1)) {
					return true;
				}
			}
		}
	}

	return false;
}

bool nQueens(vector<vector<int>>&board, int row, int n)
{
	if (row == n) {
		return true;
	}

	for (int j = 0; j < n; j++) {

		if (isAttacked(row, j, board, n)) {
			continue;
		}

		board[row][j] = 1;

		if (nQueens(board, level + 1, n)) {
			return true;
		}

		board[row][j] = 0;
	}

	return false;
}
void solveNQ(int n)
{
	vector <vector<int>> board(n, vector<int> (n, 0));
	if (solveNQUtil(board, 0, n) == false)
	{
		cout << "Not Possible";
		return;
	}
	printSolution(board, n);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n;
	cin >> n;
	solveNQ(n);

	return 0;
}
