#include <bits/stdc++.h>

using namespace std;

int mazeObstaclesHelper(int n, int m, vector<vector<int>> &mat) {
  if (n == 0 and m == 0 and mat[n][m] == 0)
    return 1;
  if (n < 0 or m < 0)
    return 0;
  if (mat[n][m] == -1)
    return 0;
  int left = mazeObstaclesHelper(n - 1, m, mat);
  int up = mazeObstaclesHelper(n, m - 1, mat);
  return left + up;
}

int mazeObstaclesHelperRecur(int n, int m, vector<vector<int>> &mat) {
  if (n >= 0 and m >= 0 and mat[n][m] == -1)
    return 0;
  if (n == 0 and m == 0)
    return 1;
  if (n < 0 or m < 0)
    return 0;
  if (mat[n][m] == -1)
    return 0;
  int left = mazeObstaclesHelperRecur(n - 1, m, mat);
  int up = mazeObstaclesHelperRecur(n, m - 1, mat);
  return left + up;
}

int mazeObstaclesHelper(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp, int mod = 1e9 + 7) {
  if (n >= 0 and m >= 0 and mat[n][m] == -1)
    return 0;
  if (n == 0 and m == 0)
    return 1;
  if (n < 0 or m < 0)
    return 0;
  if (dp[n][m] != -1)
    return dp[n][m];
  int up = mazeObstaclesHelper(n - 1, m, mat, dp) % mod;
  int left = mazeObstaclesHelper(n, m - 1, mat, dp) % mod;
  return dp[n][m] = ((left + up) % mod);
}

int mazeObstaclesHelperTabulation(int n, int m, vector<vector<int>> &mat, int mod = 1e9 + 7) {
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int up = 0, left = 0;
      if (i > 0 and mat[i][j] != -1)
        up = (dp[i - 1][j] % mod);
      if (j > 0 and mat[i][j] != -1)
        left = (dp[i][j - 1]) % mod;
      if (i == 0 and j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = ((up + left) % mod);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return (dp[n - 1][m - 1] % mod);
}

int mazeObstaclesHelperTabulation_ii(int n, int m, vector<vector<int>> &mat, int mod = 1e9 + 7) {
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 and j == 0)
        dp[i][j] = 1;
      else {
        int up = 0, left = 0;
        if (i > 0 and mat[i][j] != -1)
          up = (dp[i - 1][j] % mod);
        if (j > 0 and mat[i][j] != -1)
          left = (dp[i][j - 1] % mod);
        dp[i][j] = ((up + left) % mod);
      }
    }
  }
  return (dp[n - 1][m - 1] % mod);
}

int mazeObstaclesHelperTabulation_iii(int n, int m, vector<vector<int>> &mat, int mod = 1e9 + 7) {
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == -1)
        dp[i][j] = 0;
      else if (i == 0 and j == 0)
        dp[i][j] = 1;
      else {
        int up = 0, left = 0;
        if (i > 0)
          up = (dp[i - 1][j] % mod);
        if (j > 0 and mat[i][j] != -1)
          left = (dp[i][j - 1] % mod);
        dp[i][j] = ((up + left) % mod);
      }
    }
  }
  return (dp[n - 1][m - 1] % mod);
}

int mazeObstaclesHelperSpaceOptimization(int n, int m, vector<vector<int>> &mat, int mod = 1e9 + 7) {
  vector<int> dp(m, 0);
  for (int i = 0; i < n; i++) {
    vector<int> temp(m, 0);
    for (int j = 0; j < m; j++) {
      if (i == 0 and j == 0)
        temp[j] = 1;
      else {
        int up = 0, left = 0;
        if (i > 0 and mat[i][j] != -1)
          up = (dp[j] % mod);
        if (j > 0 and mat[i][j] != -1)
          left = (temp[j - 1] % mod);
        temp[j] = ((up + left) % mod);
      }
    }
    dp = temp;
  }

  return (dp[m - 1] % mod);
}


int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  // Write your code here
  return mazeObstaclesHelperSpaceOptimization(n, m, mat);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    cout << mazeObstacles(n, m, mat) << endl;
  }
  return 0;
}



/*
Test Case
2
2 2
0 0
0 0
3 3
0 0 0
0 -1 0
0 0 0

Output

2
2

*/