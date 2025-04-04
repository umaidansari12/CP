#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// bool checkIfRowOrColumnIsPainted(vector<vector<bool>> &visited, int i, int j) {
	// 	int cnt = 0;
	// 	for (int k = 0; k < visited[0].size(); k++) {
	// 		// cout << visited[i][k] << " ";
	// 		if (visited[i][k] == true)
	// 			cnt++;
	// 	}
	// 	// cout << endl;
	// 	if (cnt == visited[0].size())
	// 		return true;
	// 	cnt = 0;
	// 	for (int l = 0; l < visited.size(); l++) {
	// 		// cout << visited[l][j] << " ";
	// 		if (visited[l][j] == true)
	// 			cnt++;
	// 	}
	// 	// cout << endl;
	// 	if (cnt == visited.size())
	// 		return true;
	// 	return false;
	// }

	// int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
	// 	int m = mat.size(), n = mat[0].size();
	// 	unordered_map<int, pair<int, int>> mem;
	// 	vector<vector<bool>> visited(m, vector<bool>(n, false));
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++) {
	// 			mem[mat[i][j]] = {i, j};
	// 		}
	// 	}

	// 	for (int i = 0; i < arr.size(); i++) {
	// 		pair<int, int> indexes = mem[arr[i]];
	// 		visited[indexes.first][indexes.second] = true;
	// 		if (checkIfRowOrColumnIsPainted(visited, indexes.first, indexes.second))
	// 			return i;
	// 		// cout << endl;
	// 	}
	// 	return -1;
	// }
	bool checkIfRowOrColumnIsPainted(vector<vector<bool>> &visited, int i, int j) {
		int cnt = 0;
		for (int k = 0; k < visited[0].size(); k++) {
			if (visited[i][k] == true)
				cnt++;
		}
		if (cnt == visited[0].size())
			return true;
		cnt = 0;
		for (int l = 0; l < visited.size(); l++) {
			if (visited[l][j] == true)
				cnt++;
		}
		if (cnt == visited.size())
			return true;
		return false;
	}

	int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		unordered_map<int, int> mpr, mpc, mprc, mpcc;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mpr[mat[i][j]] = i;
				mpc[mat[i][j]] = j;
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			mprc[mpr[arr[i]]]++;
			mpcc[mpc[arr[i]]]++;
			if (mprc[mpr[arr[i]]] == mat[0].size() or mpcc[mpc[arr[i]]] == mat.size())
				return i;
		}
		return -1;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int _size;
		cin >> _size;
		vector<int> a(_size, 0);
		for (int i = 0; i < _size; i++) {
			cin >> a[i];
			// cout << a[i] << " ";
		}
		// cout << endl;
		int m, n;
		cin >> m >> n;
		vector<vector<int>> grid(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				// cout << grid[i][j] << " ";
			}
			// cout << endl;
		}
		Solution ob = Solution();
		cout << ob.firstCompleteIndex(a, grid) << endl;

	}
}