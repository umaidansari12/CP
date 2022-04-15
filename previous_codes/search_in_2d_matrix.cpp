#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty())
		return false;
	int n = matrix.size();
	int m = matrix[0].size();

	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (matrix[i][0] == target || matrix[i][m - 1] == target)
			return true;
		if (matrix[i][0] < target && matrix[i][m - 1] > target)
			break;
	}
	if (i == n)
		i = n - 1;
	for (int j = 0; j < m; j++)
	{
		if (matrix[i][j] == target)
			return true;
	}
	return false;
}

bool search_matrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty() || matrix[0].empty())
		return false;
	int n = matrix.size();
	int m = matrix[0].size();
	int i = 0, j = m - 1;
	while (i < n && j >= 0)
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
bool searchmatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty() || matrix[0].empty())
		return false;
	int n = matrix.size();
	int m = matrix[0].size();
	int low = 0, high = n * m - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (matrix[mid / m][mid % m] == target)
			return true;
		else if (matrix[mid / m][mid % m] < target)
			low = mid + 1;
		else
			high = mid - 1;
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
		int f = 0;
		/*for (int i = 0; i < n; i++)
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
		}*/
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
	}


	return 0;
}