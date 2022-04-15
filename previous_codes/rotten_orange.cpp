#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(int i, int j, int r, int c)
{
	if (i >= 0 && j >= 0 && i < r && j < c)
		return true;
	return false;
}

int RottenOrange(vector<vector<int>>&a, int r, int c)
{
	int no = 0;
	bool changed = false;
	while (true)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (a[i][j] == 2)
				{
					if (isSafe(i + 1, j, r, c) && a[i + 1][j] == 1)
					{
						a[i + 1][j] = a[i + 1][j] + 1;
						changed = true;
					}
					if (isSafe(i - 1, j, r, c) && a[i - 1][j] == 1)
					{
						a[i - 1][j] = a[i - 1][j] + 1;
						changed = true;
					}
					if (isSafe(i, j + 1, r, c) && a[i][j + 1] == 1)
					{
						a[i][j + 1] = a[i][j + 1] + 1;
						changed = true;
					}
					if (isSafe(i, j - 1, r, c) && a[i][j - 1] == 1)
					{
						a[i][j - 1] = a[i][j - 1] + 1;
						changed = true;
					}
				}
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << " ----- " << endl;
		if (!changed)
			break;
		changed = false;
		no++;
	}/*
	int no = 2;
	bool changed = false;
	while (true)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (a[i][j] == no)
				{
					if (isSafe(i + 1, j, r, c) && a[i + 1][j] == 1)
					{
						a[i + 1][j] = a[i][j] + 1;
						changed = true;
					}
					if (isSafe(i - 1, j, r, c) && a[i - 1][j] == 1)
					{
						a[i - 1][j] = a[i][j] + 1;
						changed = true;
					}
					if (isSafe(i, j + 1, r, c) && a[i][j + 1] == 1)
					{
						a[i][j + 1] = a[i][j] + 1;
						changed = true;
					}
					if (isSafe(i, j - 1, r, c) && a[i][j - 1] == 1)
					{
						a[i][j - 1] = a[i][j] + 1;
						changed = true;
					}
				}
			}
		}
		if (!changed)
			break;
		changed = false;
		no++;
	}*/
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] == 1)
			{
				return -1;
			}
	return no;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int r, c;
		cin >> r >> c;
		vector<vector<int>> a(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> a[i][j];

		/*for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		*/
		cout << RottenOrange(a, r, c) << endl;

	}


	return 0;
}