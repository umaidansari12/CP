#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//C++

class Solution
{
private:
	int R, C;
	bool isvalid(int i, int j)
	{
		return (i >= 0 && j >= 0 && i < R && j < C);
	}

	struct ele {
		int x, y;
	};

	bool isdelim(ele temp)
	{
		return (temp.x == -1 && temp.y == -1);
	}

	bool checkall(vector<vector<int>> hospital)
	{
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (hospital[i][j] == 1)
					return true;
		return false;
	}
public:
	int helpaterp(vector<vector<int>> hospital)
	{
		R = hospital.size();
		C = hospital[0].size();
		queue<ele> Q;
		ele temp;
		int ans = 0;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (hospital[i][j] == 2)
				{
					temp.x = i;
					temp.y = j;
					Q.push(temp);
				}
			}
		}
		temp.x = -1;
		temp.y = -1;
		Q.push(temp);

		while (!Q.empty())
		{

			bool flag = false;

			while (!isdelim(Q.front()))
			{
				temp = Q.front();

				if (isvalid(temp.x + 1, temp.y) && hospital[temp.x + 1][temp.y] == 1)
				{

					if (!flag) ans++, flag = true;
					hospital[temp.x + 1][temp.y] = 2;
					temp.x++;
					Q.push(temp);

					temp.x--;
				}
				if (isvalid(temp.x - 1, temp.y) && hospital[temp.x - 1][temp.y] == 1) {
					if (!flag) ans++, flag = true;
					hospital[temp.x - 1][temp.y] = 2;
					temp.x--;
					Q.push(temp);
					temp.x++;
				}
				if (isvalid(temp.x, temp.y + 1) && hospital[temp.x][temp.y + 1] == 1) {
					if (!flag) ans++, flag = true;
					hospital[temp.x][temp.y + 1] = 2;
					temp.y++;
					Q.push(temp);
					temp.y--;
				}
				if (isvalid(temp.x, temp.y - 1) && hospital[temp.x][temp.y - 1] == 1) {
					if (!flag) ans++, flag = true;
					hospital[temp.x][temp.y - 1] = 2;
					temp.y--;
					Q.push(temp);
				}
				Q.pop();
			}
			Q.pop();
			if (!Q.empty()) {
				temp.x = -1;
				temp.y = -1;
				Q.push(temp);
			}
		}


		return (checkall(hospital)) ? -1 : ans;

	}
};
bool isSafe(int i, int j, int r, int c)
{
	if (i >= 0 && i < r && j >= 0 && j < c)
		return true;
	return false;
}

bool isDelim(queue<pair<int, int>> p)
{
	return (p.front().first == -1 && p.front().second == -1);
}

int RottenOrange(vector<vector<int>>a, int r, int c)
{
	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] == 2)
				q.push({i, j});
	q.push({ -1, -1});
	int ans = 0;
	/*while (!q.empty())
	{
		cout << q.front().first << " " << q.front().second << endl;
		q.pop();
	}*/
	while (!q.empty())
	{
		bool flag = false;
		while (!isDelim(q))
		{
			int x = q.front().first;
			int y = q.front().second;
			if (isSafe(x + 1, y, r, c) && a[x + 1][y] == 1)
			{
				if (!flag)
				{
					flag = true;
					ans++;
				}
				a[x + 1][y] = 2;
				q.push({x + 1, y});
			}
			if (isSafe(x - 1, y, r, c) && a[x - 1][y] == 1)
			{
				if (!flag)
				{
					flag = true;
					ans++;
				}
				a[x - 1][y] = 2;
				q.push({x - 1, y});
			}
			if (isSafe(x, y + 1, r, c) && a[x][y + 1] == 1)
			{
				if (!flag)
				{
					flag = true;
					ans++;
				}
				a[x][y + 1] = 2;
				q.push({x, y + 1});
			}
			if (isSafe(x, y - 1, r, c) && a[x][y - 1] == 1)
			{
				if (!flag)
				{
					flag = true;
					ans++;
				}
				a[x][y - 1] = 2;
				q.push({x, y - 1});
			}
			q.pop();
		}
		q.pop();
		if (!q.empty())
			q.push({ -1, -1});

	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] == 1)
				return -1;

	return ans;
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
		cout << RottenOrange(a, r, c) << endl;
	}

	return 0;
}