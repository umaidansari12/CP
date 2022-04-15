#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int p, n;
	cin >> n >> p;
	vector<vector<int>> a(n, vector<int> (n, 0));
	while (p--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] == 1)
		{
			count++;
			continue;
		}
		else
		{
			for (int j = 1; j < n; j++)
			{
				if (a[j][i] == 1)
				{
					count++;
					break;
				}
			}
		}
	}
	cout << count << endl;

	return 0;
}