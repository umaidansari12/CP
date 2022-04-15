// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/*
Easy approach -> Use DFS + Memorization
Create a dp of size n*m
What we are going to store in our dp[i][j] is the Lonest Increasing Path
from row =i and col = j
We will use DFS to Reach the maximum depth i.e. the longest increasing path here .
To avoid calculating the Longest Increasing path for a cell multiple times we will use the concept of memorization and store the value in our dp
Here we don't need to keep a visited matrix as
Suppose the matrix is :
3 2
5 6
Now from 3 we will go to 5
Now from 5 since 3 is smaller than 5 so we will never go to 3 .
So we will never go toward the path from which we are coming .


*/

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int dirX[4] = { -1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};

    int solve(vector<vector<int>> &a, int i, int j, int n, int m, int curr_val, vector<vector<int>> &dp) {
        if (i<0 or j<0 or i >= n or j >= m or curr_val >= a[i][j])
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int result = 0;
        for (int k = 0; k < 4; k++) {
            int nextRow = i + dirX[k];
            int nextCol = j + dirY[k];
            result = max(result, 1 + solve(a, nextRow, nextCol, n, m, a[i][j], dp));
        }
        return dp[i][j] = result;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int length = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curr = INT_MIN;
                int temp = solve(matrix, i, j, n, m, curr, dp);
                length = max(length, temp);
            }
        }
        return length;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}


class Solution {
public:
    vector<int> X{ -1, 0, 1, 0};
    vector<int> Y{0, 1, 0, -1};
    bool isSafe(vector<vector<int>> &matrix, int i, int j, int row, int col, int prev) {
        return i >= 0 and j >= 0 and i < row and j < col and prev < matrix[i][j];
    }
    int getLip(vector<vector<int>> &matrix, int i, int j, int row, int col, int prev, vector<vector<int>> &dp) {
        if (!isSafe(matrix, i, j, row, col, prev))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + X[k];
            int y = j + Y[k];
            ans = max(ans, 1 + getLip(matrix, x, y, row, col, matrix[i][j], dp));
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        if (row == 0)
            return 0;
        if (row == 1 and col == 1)
            return 1;
        int ans = 1;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans = max(ans, getLip(matrix, i, j, row, col, INT_MIN, dp));
            }
        }
        return ans;
    }
};