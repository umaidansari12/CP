#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void matrixRotation(vector<vector<int>> &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		reverse(a[i].begin(), a[i].end());
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
				swap(a[i][j], a[j][i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
	}
	cout << endl;
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
		vector<vector<int>> a(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		matrixRotation(a, n);
	}


	return 0;
}