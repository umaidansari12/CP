#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool sourceIsDestination(int x, int y, int r, int c) {
	return (x == 0 and y == 0) || (x == r - 1 and y == c - 1) || (x == 0 and y == c - 1) || (x == r - 1 and y == 0);
}

bool isValid(vector<vector<int>> &graph, vector<vector<bool>> &visited, int r, int c, int x, int y) {
	return x >= 0 and x<r and y >= 0 and y < c and !graph[x][y] and !visited[x][y];
}


int minimum_distance(vector<vector<int>> &graph, int r, int c, int sourceX, int sourceY) {

	if (sourceIsDestination(sourceX, sourceY, r, c))
		return 0;

	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	queue<pair<int, int>> q;
	q.push({sourceX, sourceY});

	vector<vector<bool>> visited(r, vector<bool>(c, false));
	vector<vector<int>> minDistance(r, vector<int>(c, INT_MAX));


	minDistance[sourceX][sourceY] = 0;
	visited[sourceX][sourceY] = true;
	q.push({sourceX, sourceY});

	while (!q.empty()) {
		pair<int, int> current_cell = q.front();
		for (int i = 0; i < 4; i++) {
			int newX = current_cell.first + dx[i];
			int newY = current_cell.second + dy[i];
			if (isValid(graph, visited, r, c, newX, newY)) {
				minDistance[newX][newY] = min(minDistance[current_cell.first][current_cell.second] + 1, minDistance[newX][newY]);
				visited[newX][newY] = true;
				q.push({newX, newY});
			}
		}
		q.pop();
	}


	int ans = INT_MAX;

	ans = min(ans, min(minDistance[0][0], min(minDistance[r - 1][c - 1], min(minDistance[0][c - 1], minDistance[r - 1][0]))));

	if (ans == INT_MAX)
		return -1;

	return ans;
}


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int r, c, x, y;
		cin >> r >> c >> x >> y;

		vector<vector<int>> graph(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> graph[i][j];
			}
		}


		cout << minimum_distance(graph, r, c, x, y) << endl;
	}
}