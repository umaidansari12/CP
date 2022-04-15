#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(int x, int y, int n) {
	return x >= 0 and x<n and y >= 0 and y < n;
}

int demolitionRobot(vector<vector<int>> &matrix, int n) {
	if (matrix.empty())
		return -1;
	int dx[] = { -1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<pair<int, int>, int>> q;
	q.push({make_pair(0, 0), 0});
	while (!q.empty()) {
		pair<int, int> coordinates = q.front().first;
		int distance = q.front().second;
		int x = coordinates.first;
		int y = coordinates.second;
		q.pop();
		if (matrix[x][y] == 9)
			return distance;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isSafe(nx, ny, n) and matrix[nx][ny] != 0 and visited[nx] [ny] == false) {
				visited[nx][ny] = true;
				q.push({make_pair(nx, ny), distance + 1});
			}
		}
	}
	return -1;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}

		cout << demolitionRobot(matrix, n) << endl;
	}


	return 0;
}