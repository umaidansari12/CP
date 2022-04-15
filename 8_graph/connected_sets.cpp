#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool isSafe(int x, int y, int n) {
    return x >= 0 and y >= 0 and x < n and y < n;
}

void dfs(vector<vector<int>> &grid, int i, int j, int n, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isSafe(x, y, n) and !visited[x][y] and grid[x][y] == 1) {
            dfs(grid, x, y, n, visited);
        }
    }

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        int n, count = 0;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] and grid[i][j] == 1) {
                    count++;
                    dfs(grid, i, j, n, visited);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
