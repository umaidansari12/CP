#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int row, int col, int idx, vector<vector<bool>> &visited, vector<vector<char>> &board, int n, int m, string &word) {
        if (idx == word.size()) {
            return true;
        }
        if (row < 0 or row >= n or col < 0 or col >= m or board[row][col] != word[idx] or visited[row][col] == true)
            return false;
        visited[row][col] = true;
        bool result = dfs(row + 1, col, idx + 1, visited, board, n, m, word) or dfs(row - 1, col, idx + 1, visited, board, n, m, word) or dfs(row, col + 1, idx + 1, visited, board, n, m, word) or dfs(row, col - 1, idx + 1, visited, board, n, m, word);
        visited[row][col] = false;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, visited, board, n, m, word))
                    return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        cout << word << endl;

        int directions[4][2] = {{0, 1}, { -1, 0}, {0, -1}, {1, 0}};

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int cur_idx = 0;
        int _size = word.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if (board[i][j] == word[cur_idx]) {
                    q.push({{i, j}, cur_idx});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        pair<pair<int, int>, int> curr = q.front();
                        int row = curr.first.first;
                        int col = curr.first.second;
                        int idx = curr.second;
                        cout << row << col << idx << endl;
                        q.pop();
                        visited[row][col] = true;
                        if (idx == _size - 1)
                            return true;
                        for (int i = 0; i < 4; i++) {
                            int next_row = row + directions[i][0];
                            int next_col = col + directions[i][1];
                            // if(next_row>=0 and next_row < n and next_col >=0 and next_col < m and visited[next_row][next_col] == false and board[next_row][next_col]==word[idx]){
                            if (next_row >= 0 and next_row < n and next_col >= 0 and next_col < m and visited[next_row][next_col] == false and board[next_row][next_col] == word[idx + 1]) {
                                q.push({{next_row, next_col}, idx + 1});
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
        // while (!q.empty()) {
        //     pair<pair<int, int>, int> curr = q.front();
        //     int row = curr.first.first;
        //     int col = curr.first.second;
        //     int idx = curr.second;
        //     cout << row << col << idx << endl;
        //     q.pop();
        //     visited[row][col] = true;
        //     if (idx == _size)
        //         return true;
        //     for (int i = 0; i < 4; i++) {
        //         int next_row = row + directions[i][0];
        //         int next_col = col + directions[i][1];
        //         // if(next_row>=0 and next_row < n and next_col >=0 and next_col < m and visited[next_row][next_col] == false and board[next_row][next_col]==word[idx]){
        //         if (next_row >= 0 and next_row < n and next_col >= 0 and next_col < m and visited[next_row][next_col] == false and board[next_row][next_col] == word[idx + 1]) {
        //             q.push({{next_row, next_col}, idx + 1});
        //         }
        //     }
        // }

        return false;

    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }
        string word;
        cin >> word;
        Solution ob = Solution();
        cout << ob.exist(board, word) << endl;
    }
}