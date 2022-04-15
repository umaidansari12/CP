#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int matSearchBrute(vector <vector <int>> &mat, int N, int M, int X)
	{
		// your code here
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (mat[i][j] == X)
					return 1;
			}
		}
		return 0;
	}
	int matSearchOptimal(vector <vector <int>> &mat, int N, int M, int X)
	{
		// your code here
		for (int i = 0; i < N; i++)
		{
			int left = 0, right = M - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (mat[i][mid] == X)
					return 1;
				else if (mat[i][mid] < X)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return 0;
	}
	int matSearchOptimalOptimized(vector <vector <int>> &mat, int N, int M, int X)
	{
		// your code here
		for (int i = 0; i < N; i++)
		{
			int left = 0, right = M - 1;
			if (X == mat[i][left] || X == mat[i][right])
				return 1;
			else if (X > mat[i][left] && X < mat[i][right])
			{
				while (left <= right)
				{
					int mid = (left + right) / 2;
					if (mat[i][mid] == X)
						return 1;
					else if (mat[i][mid] < X)
					{
						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
			}
		}
		return 0;
	}
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
		// your code here
		int i = 0, j = M - 1;
		while (i < N && j >= 0)
		{
			if (mat[i][j] == X)
				return 1;
			else if (mat[i][j] < X)
				i++;
			else
				j--;
		}
		return 0;
	}
};

/*Look at the matrix properties carefully. Basically you are given the elements in sorted order already.
How can you exploit this property now?
If you write down the numbers of row 1 followed by numbers in row2, row3 and so on,
do you think the resulting array would be sorted ?
If yes, how do you search for a number efficiently in a sorted array ?
*/
int searchMatrix(vector<vector<int> > &A, int B) {
	int N = A.size();
	int M = A[0].size();
	int start = 0, end = N * M - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int x = mid / M;
		int y = mid % M;
		if (A[x][y] == B) return 1;
		if (B < A[x][y]) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}
i
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
	int n = A.size();
	int m = A[0].size();
	for (int i = 0; i < n; i++)
	{
		int low = 0, high = m - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (A[i][mid] == B) {
				return 1;
			}
			if (A[i][mid] > B) {
				high = mid - 1;
			}
			else if (A[i][mid] < B) {
				low = mid + 1;
			}
		}
	}
	return 0;
}
class Solution2 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size(), c = matrix[0].size();
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				if (matrix[i][j] == target)
					return true;
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size(), c = matrix[0].size();
		int left = 0, right = (r * c) - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			int i = mid / c;
			int j = mid % c;
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size(), c = matrix[0].size();
		for (int i = 0; i < r; i++)
		{
			int left = 0, right = c - 1;
			if (matrix[i][left] == target || matrix[i][right] == target)
				return true;
			else if (matrix[i][left] < target && matrix[i][right] > target)
			{
				while (left <= right)
				{
					int mid = (left + right) / 2;
					if (matrix[i][mid] == target)
						return true;
					else if (matrix[i][mid] < target)
						left = mid + 1;
					else
						right = mid - 1;
				}
			}
		}
		return false;
	}
	bool searchMatrixOptimized(vector<vector<int>>& matrix, int target) {
		int r = matrix.size(), c = matrix[0].size();
		int i = 0, j = c - 1;
		while (i < r && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				i++;
			else
				j--;
		}
		return false;
	}
};

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int r = matrix.size(), c = matrix[0].size();
	for (int i = 0; i < r; i++)
	{
		int left = 0, right = c - 1;
		if (matrix[i][left] == target || matrix[i][right] == target)
			return true;
		else if (matrix[i][left] < target && matrix[i][right] > target)
		{
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (matrix[i][mid] == target)
					return true;
				else if (matrix[i][mid] < target)
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
	}
	return false;
}

int main()
{
	ios_base:: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, x;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		cin >> x;
		if (searchMatrix(a, x))
			cout << 1 << endl;
		else
			cout << 0 << endl;
		/*int f = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == x)
				{
					f = 1;
					break;
				}
			}
		}
		int i = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i][0] <= x && a[i][m - 1])
				break;
		}
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == x)
			{
				f = 1;
				break;
			}
		}
		int i = 0, j = m - 1;
		while (i < n && j >= 0)
		{
			if (a[i][j] == x)
			{
				f = 1;
				break;
			}
			else if (a[i][j] > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		if (f == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		}*/


		return 0;
	}
}