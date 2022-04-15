#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<int, int> searchBrute(int m, int n, vector<vector<int>> v, int k) {
	//write your code here.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == k)
				return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}
pair<int, int> searchBetter(int m, int n, vector<vector<int>> v, int k) {
	//write your code here.
	for (int i = 0; i < m; i++)
	{
		if (k >= v[i][0] and v[i][n - 1] >= k)
		{
			int s = 0, e = n - 1;
			while (s <= e)
			{
				int mid = (s + e) / 2;
				if (v[i][mid] == k)
				{
					return make_pair(i, mid);
				}
				else if (v[i][mid] < k)
					s = mid + 1;
				else
					e = mid - 1;
			}
		}
	}
	return make_pair(-1, -1);
}

pair<int, int> search(int m, int n, vector<vector<int>> v, int k) {
	//write your code here.
	int i = 0, j = n - 1;
	while (i < m && j >= 0)
	{
		if (v[i][j] == k)
			return make_pair(i, j);
		else if (v[i][j] < k)
			i++;
		else
			j--;
	}
	return make_pair(-1, -1);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int m, n, k;
		cin >> m >> n >> k;
		vector<vector<int>> a(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		pair<int, int> p = search(m, n, a, k);
		cout << p.first << " " << p.second << endl;

	}

	return 0;
}