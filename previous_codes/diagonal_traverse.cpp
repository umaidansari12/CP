#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& a) {
		int m = a.size(), n = a[0].size(), flag = 0;
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			if (flag)
			{
				int j = 0, k = i;
				while (j < m && k >= 0)
				{
					res.push_back(a[j++][k--]);
				}
				flag = 0;
			}
			else
			{
				int j = 0, k = i;
				vector<int> r;
				while (j < m && k >= 0)
				{
					r.push_back(a[j++][k--]);
				}
				for (int i = r.size() - 1; i >= 0; i--)
					res.push_back(r[i]);
				flag = 1;
			}
		}
		for (int j = 1; j < m; j++)
		{
			if (flag)
			{
				int row = j, col = n - 1;
				while (row < m && col >= 0)
				{
					res.push_back(a[row++][col--]);
				}
				flag = 0;
			}
			else
			{
				int row = j, col = n - 1;
				vector<int> r;
				while (row < m && col >= 0)
				{
					r.push_back(a[row++][col--]);
				}
				for (int i = r.size() - 1; i >= 0; i--)
					res.push_back(r[i]);
				flag = 1;
			}

		}
		return res;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int m, n, flag = 0;
		cin >> m >> n;
		int a[m][n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		for (int i = 0; i < m; i++)
		{
			if (flag)
			{
				int row = 0, col = i;
				while (row < m && col >= 0)
				{
					cout << a[row++][col--] << " ";
				}
				flag = 0;
			}
			else
			{
				int row = i, col = 0;
				while (row >= 0 && col < n)
				{
					cout << a[row--][col++] << " ";
				}
				flag = 1;
			}
		}
		flag = 1;
		for (int i = 1; i < n; i++)
		{
			if (flag)
			{
				int row = m - 1, col = i;
				while (row >= 0 && col < n)
				{
					cout << a[row--][col++] << " ";
				}
				flag = 0;
			}
			else
			{
				int row = i, col = n - 1;
				while (row < m && col >= 0)
				{
					cout << a[row++][col--] << " ";
				}
				flag = 1;
			}
		}
		cout << endl;
	}


	return 0;
}