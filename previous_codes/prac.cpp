#include <bits/stdc++.h>

using namespace std;
using ll = long long;




int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		//vector<vector<int>> res(n, vector<int>(m, 0));
		//vector<int> row(n, 0);
		//vector<int> col(m, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		int col0 = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i][0] == 0)
				col0 = 0;
			for (int j = 1; j < m; j++)
			{
				if (a[i][j] == 0)
				{
					a[0][j] = a[i][0] = 0;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 1; j--)
			{
				if (a[0][i] == 0 || a[0][j] == 0)
				{
					a[i][j] = 0;
				}
			}
			if (col0 == 0)
				a[i][0] = 0;
		}

		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0)
				{
					for (int k = 0; k < n; k++)
					{
						a[k][j] = -1;
					}
					for (int k = 0; k < n; k++)
					{
						a[i][k] = -1;
					}

				}
			}
		}*/


		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == 0)
				{
					row[i] = 1;
					col[j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (row[i] || col[j])
				{
					a[i][j] = 0;
				}
			}
		}
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0)
				{
					for (int k = 0; k < m; k++)
					{
						res[i][k] = 0;
					}
					for (int k = 0; k < n; k++)
					{
						res[k][j] = 0;
					}
				}
			}
		}*/
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == -1)
					a[i][j] = 0;
				cout << a[i][j] << " ";
			}
			cout << endl;
		}



		/*for (int i = 0; i < n; i++)
		{
			int sum = a[i];
			for (int j = i + 1; j < n; j++)
			{
				if (sum == k)
				{
					s = i;
					e = j;
					break;
				}
				if (sum > k || j == n)
					break;n
				sum += a[j];
				//cout << a[j] << " ";
			}
			//cout << endl;
		}
		int i = 0, j = 0, sum = a[0], flag = 0;
		while (j != n - 1)
		{
			if (sum + a[j + 1] < k)
			{
				sum += a[++j];
			}
			else if (sum == k)
			{
				flag = 1;
				s = i + 1;
				e = j + 1;
				break;
			}
			else if (sum + a[j + 1] == k)
			{
				j++;
				s = i + 1;
				e = j + 1;
				break;
			}
			else
			{
				sum -= a[i++];
			}
		}
		cout << s << " " << e << endl;*/
	}


	return 0;
}