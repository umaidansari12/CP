#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isNotSafe(vector<vector<int>> &a, int i, int j, int n, int dist) {
	if (i < 0 || j < 0 || i >= n || j >= n || (a[i][j] != 0 && a[i][j] <= dist))
		return true;
	return false;
}



void dfs(vector<vector<int>> &a, int i, int j, int n, int dist = 1) {
	if (isNotSafe(a, i, j, n, dist))
		return;
	a[i][j] = dist;
	dfs(a, i - 1, j, n, dist + 1);
	dfs(a, i + 1, j, n, dist + 1);
	dfs(a, i, j - 1, n, dist + 1);
	dfs(a, i, j + 1, n, dist + 1);
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
		vector<vector<int>> a(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					a[i][j] = 0;
					dfs(a, i, j, n);
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > 1)
					ans = max(ans, a[i][j] - 1);
			}
		}
		cout << ans << endl;

	}


	return 0;
}

class Solution {
public:
	bool isNotSafe(vector<vector<int>> &a, int i, int j, int n, int dist) {
		if (i < 0 || j < 0 || i >= n || j >= n || (a[i][j] != 0 && a[i][j] <= dist))
			return true;
		return false;
	}
	void dfs(vector<vector<int>> &a, int i, int j, int n, int dist = 1) {
		if (isNotSafe(a, i, j, n, dist))
			return;
		a[i][j] = dist;
		dfs(a, i - 1, j, n, dist + 1);
		dfs(a, i + 1, j, n, dist + 1);
		dfs(a, i, j - 1, n, dist + 1);
		dfs(a, i, j + 1, n, dist + 1);
	}

	int maxDistance(vector<vector<int>>& a) {
		int n = a.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					a[i][j] = 0;
					dfs(a, i, j, n);
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > 1)
					ans = max(ans, a[i][j] - 1);
			}
		}
		return ans;

	}
};

// we are doing multisource bfs

class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		queue<pair<int, int>> q;
		int n = grid.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					q.push({i, j});
				}
			}
		}
		//either no land is there or everywhere there is land no water  is there in both case we cant find the distance to the nearest land cell so we return -1
		if (q.size() == 0 or q.size() == (n * n))
			return -1;
		int dirX[] = { -1, 0, 1, 0};
		int dirY[] = {0, 1, 0, -1};
		int level = -1; //we just need to count how many levels are there levels signifies distance from the current land cell to water
		while (!q.empty()) {
			level++;
			int size = q.size();
			while (size--) {
				pair<int, int> curr = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nextRow = curr.first + dirX[i];
					int nextCol = curr.second + dirY[i];
					if (nextRow<0 or nextCol<0 or nextRow >= n or nextCol >= n or grid[nextRow][nextCol] == 1)
						continue;
					q.push({nextRow, nextCol});
					grid[nextRow][nextCol] = 1;
				}
			}
		}
		return level;

	}
};