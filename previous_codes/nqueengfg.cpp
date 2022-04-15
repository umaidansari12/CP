#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* A utility function to print solution */
void printSolution(vector<vector<int>> board, int N, vector<vector<int>>&res)
{
	vector<int> r;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (board[i][j])
				r.push_back(j + 1);
	}
	res.push_back(r);
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(vector<vector<int>> board, int row, int col, int N)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(vector<vector<int>> board, int col, int N, vector<vector<int>>& r)
{
	/* base case: If all queens are placed
	then return true */
	if (col == N)
	{
		printSolution(board, N, r);
		return true;

	}

	/* Consider this column and try placing
	this queen in all rows one by one */
	bool res = false;
	for (int i = 0; i < N; i++)
	{
		/* Check if queen can be placed on
		board[i][col] */
		if ( isSafe(board, i, col, N) )
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			// Make result true if any placement
			// is possible
			res = solveNQUtil(board, col + 1, N, r) || res;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If queen can not be place in any row in
	    this column col then return false */
	return res;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
void solveNQ(int n)
{
	vector<vector<int>> board(n, vector<int> (n, 0));
	vector<vector<int>> res;
	if (solveNQUtil(board, 0, n, res) == false)
	{
		cout << -1 << endl;
		return ;
	}
	sort(res.begin(), res.end());
	for (vector<int> r : res)
	{
		cout << "[";
		for (int i : r)
			cout << i << " ";
		cout << "]";
	}
	cout << endl;


	return ;
}

// driver program to test above function

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
		solveNQ(n);
	}


	return 0;
}