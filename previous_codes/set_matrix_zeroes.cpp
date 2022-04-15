#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//O(n2)
void set_zeroes(vector<vector<int>>& matrix)
{
	int r = matrix.size();
	int c = matrix[0].size();
	cout << r << " " << c << endl;
	vector<vector<int>> result_matrix(r, vector<int> (c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			result_matrix[i][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 0; k < r; k++)
				{
					result_matrix[k][j] = 0;
				}
				for (int k = 0; k < c; k++)
				{
					result_matrix[i][k] = 0;
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << result_matrix[i][j] << " ";
		}
		cout << endl;
	}
}
//O(m+n) space still not the best solution you can use O(mn) space i.e another array
void setZeroes(vector<vector<int>>& matrix) {
	int r = matrix.size();
	int c = matrix[0].size();
	vector<bool> row_zero(r);
	vector<bool> col_zero(c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (matrix[i][j] == 0)
			{
				row_zero[i] = true;
				col_zero[j] = true;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (row_zero[i] || col_zero[j])
				matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int rownum = matrix.size();
		if (rownum == 0)  return;
		int colnum = matrix[0].size();
		if (colnum == 0)  return;

		bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

		// Does first row have zero?
		for (int j = 0; j < colnum; ++j) {
			if (matrix[0][j] == 0) {
				hasZeroFirstRow = true;
				break;
			}
		}

		// Does first column have zero?
		for (int i = 0; i < rownum; ++i) {
			if (matrix[i][0] == 0) {
				hasZeroFirstColumn = true;
				break;
			}
		}

		// find zeroes and store the info in first row and column
		for (int i = 1; i < rownum; ++i) {
			for (int j = 1; j < colnum; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		// set zeroes except the first row and column
		for (int i = 1; i < rownum; ++i) {
			for (int j = 1; j < colnum; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
			}
		}

		// set zeroes for first row and column if needed
		if (hasZeroFirstRow) {
			for (int j = 0; j < colnum; ++j) {
				matrix[0][j] = 0;
			}
		}
		if (hasZeroFirstColumn) {
			for (int i = 0; i < rownum; ++i) {
				matrix[i][0] = 0;
			}
		}
	}
};
void setzeroes(vector<vector<int>>& matrix)
{
	int r = matrix.size();
	int c = matrix[0].size();
	int col0 = 1;
	for (int i = 0; i < r; i++)
	{
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < c; j++)
		{
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
		}
	}
	for (int i = r - 1; i >= 0; i--)
	{
		for (int j = c - 1; j >= 1; j--)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
		if (col0 == 0)
			matrix[i][0] = 0;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void set_Zeroes(vector<vector<int>>& matrix) {
	int r = matrix.size();
	int c = matrix[0].size();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 0; k < r; k++)
				{
					if (matrix[k][j] > 0)
						matrix[k][j] = -1;
				}
				for (int k = 0; k < c; k++)
				{
					if (matrix[i][k] > 0)
						matrix[i][k] = -1;
				}

			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (matrix[i][j] == -1)
				matrix[i][j] = 0;
		}
	}
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
		int r, c;
		cin >> r >> c;
		vector <vector<int>> matrix(r, vector<int> (c, 0));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> matrix[i][j];
			}
		}
		setzeroes(matrix);
		cout << "Done!" << endl;
	}


	return 0;
}