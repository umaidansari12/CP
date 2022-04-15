#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(int i, int j, vector<string>&G, vector<string>&P, int r, int c)
{
	for (int row = 0; row < r; row++)
	{
		//cout << G[i + row].substr(j, c) << endl;
		if (P[row] != G[i + row].substr(j, c))
			return false;
	}
	return true;
}

string gridSearch1(vector<string> G, vector<string> P) {
	int R = G.size(), C = G[0].size(), r = P.size(), c = P[0].size();
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (G[i][j] == P[0][0])
			{
				if (check(i, j, G, P, r, c))
					return "YES";
			}
		}
	}
	return "NO";
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
		int R, C, r, c;
		cin >> R >> C;
		vector<string> G(R);
		for (int i = 0; i < R; i++)
			cin >> G[i];
		cin >> r >> c;
		vector<string> P(r);
		for (int i = 0; i < r; i++)
			cin >> P[i];
		cout << gridSearch(G, P) << endl;
	}


	return 0;
}