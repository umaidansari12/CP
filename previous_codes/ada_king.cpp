#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		cin >> m;
		vector<vector<char>> a(8, vector<char>(8, 'X'));
		int count = 0, flag = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				a[i][j] = '.';
				count++;
				if (count == m)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
		a[0][0] = 'O';
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

/*vector<pair<int, int>>countSquares(int r, int c, int m)
{

	// To store the count of squares
	int squares = 0;
	vector <pair<int, int>>re;

	// Check all squares of
	// the chessboard
	int x = 0, y = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {

			// Check if square (i, j) is
			// at a distance <= m units
			// from king's current position
			if (max(abs(i - r), abs(j - c)) <= m)
			{
				x = i;
				y = j;
				squares++;
			}

		}
	}

	// Return count of squares
	re.push_back(make_pair(x, y));

	return re;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		cin >> m;
		vector <pair<int, int>> r = countSquares(0, 0, m);
		int x, y;
		for (auto i : r)
		{
			x = i.first;
			y = i.second;
		}
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)
			{
				if (i == x && j == y)
				{
					cout << "O";
				}
				/*else if ((i == x + 1) || (i == x - 1) || (j == y + 1) || (j == y - 1) || (i == x + 1 && j == y - 1) || (i == x + 1 && j == y + 1) || (i == x - 1 && j == y - 1) || (i == x - 1 && j == y + 1))
				{
					cout << "X";
				}
				else if ((i - x) == m && (j - y) == m)
				{
					cout << "X";
				}
				else
				{
					cout << ".";
				}

			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}*/