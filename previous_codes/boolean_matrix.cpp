#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*1) Create two temporary arrays row[M] and col[N]. Initialize all values of row[] and col[] as 0.
2) Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as true, then mark row[i] and col[j] as true.
3) Traverse the input matrix mat[M][N] again. For each entry mat[i][j], check the values of row[i] and col[j].
 If any of the two values (row[i] or col[j]) is true, then mark mat[i][j] as true.

*/

class Solution
{
public:
	void booleanMatrix(vector<vector<int> > &matrix)
	{
		int R = matrix.size();
		int C = matrix[0].size();

		vector<int> row(R, 0);
		vector<int> col(C, 0);

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (matrix[i][j] == 1) {
					row[i] = col[j] = 1;
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (row[i] || col[j]) {
					matrix[i][j] = 1;
				}
			}
		}
	}
};



class Solution
{
public:
	void booleanMatrix(vector<vector<int> > &matrix)
	{
		int R = matrix.size();
		int C = matrix[0].size();

		vector<int> row(R, 0);
		vector<int> col(C, 0);

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (matrix[i][j] == 1) {
					row[i] = col[j] = 1;
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (row[i] || col[j]) {
					matrix[i][j] = 1;
				}
			}
		}
	}
};


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
		queue<pair<int, int>> q;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == 1)
					q.push(make_pair(i, j));
			}
		while (!q.empty())
		{
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < c; i++)
			{
				a[p.first][i] = 1;
			}
			for (int i = 0; i < r; i++)
			{
				a[i][p.second] = 1;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j <	c; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}


	}


	return 0;
}