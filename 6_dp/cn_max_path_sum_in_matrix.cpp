#include<bits/stdc++.h>


using namespace std;


//  x-directions and y-directions
int dx[] = {1, 1, 1};
int dy[] = {0, -1, 1};

bool isValid(int row, int col, int n, int m)
{
    return (row >= 0 && col >= 0 && row < n && col < m);
}

int getMaxPathSumHelper(int row, int col, vector<vector<int>> &matrix, int n, int m)
{

    //  Base case: we are at last row
    if (row == n - 1)
    {
        return matrix[row][col];
    }

    int maxPathSum, currPathSum = INT_MIN;

    //  Get the maximum path sum from (row,col) to the any cell of last row, excluding (row,col) cell
    for (int i = 0; i < 3; i++)
    {
        //  Get new cell
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];

        //  Check whether new cell is a valid cell or not?
        if (isValid(nextRow, nextCol, n, m))
        {
            currPathSum = max(currPathSum, getMaxPathSumHelper(nextRow, nextCol, matrix, n, m));
        }
    }
    //  Include (row, col) cell into maximum path sum
    maxPathSum = matrix[row][col] + currPathSum;

    return maxPathSum;
}

int getMaxPathSumTopDownHelper(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp, int n, int m)
{

    //  Base case: we are at last row
    if (row == n - 1)
    {
        return matrix[row][col];
    }

    //  Check whether we have already a solution or not?
    if (dp[row][col] != INT_MIN)
    {
        return dp[row][col];
    }

    int maxPathSum, currPathSum = INT_MIN;

    //  Get the maximum path sum from (row,col) to the any cell of last row, excluding (row,col) cell
    for (int i = 0; i < 3; i++)
    {
        //  Get new cell
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];

        //  Check whether new cell is a valid cell or not?
        if (isValid(nextRow, nextCol, n, m))
        {
            currPathSum = max(currPathSum, getMaxPathSumHelper(nextRow, nextCol, matrix, dp, n, m));
        }
    }

    //  Include (row, col) cell into maximum path sum
    maxPathSum = matrix[row][col] + currPathSum;

    //  Store in dp to avoid redundant calls
    dp[row][col] = maxPathSum;

    return maxPathSum;
}


int getMaxPathSumTopDown(vector<vector<int>> &matrix)
{
    int maxPathSum = INT_MIN, currPathSum;

    int n = matrix.size();
    int m = matrix[0].size();

    //  For storing the output of each cell so that we can avoid redundant calls
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

    for (int i = 0; i < m; i++)
    {
        currPathSum = getMaxPathSumHelper(0, i, matrix, dp, n, m);
        if (currPathSum > maxPathSum)
        {
            maxPathSum = currPathSum;
        }
    }

    return maxPathSum;
}

int getMaxPathSumRecur(vector<vector<int>> &matrix)
{
    int maxPathSum = INT_MIN, currPathSum;

    int n = matrix.size();
    int m = matrix[0].size();

    //  Explore all possible from all cell of the first row to the any cell of the last row
    for (int i = 0; i < m; i++)
    {
        currPathSum = getMaxPathSumHelper(0, i, matrix, n, m);

        //  Check, If we get better path
        if (currPathSum > maxPathSum)
        {
            maxPathSum = currPathSum;
        }
    }

    return maxPathSum;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    int dp[n][m] = {0};
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
                dp[i][j] = matrix[i][j];
            else
            {
                int max1 = INT_MIN;
                max1 = max(max1, dp[i - 1][j]);
                //cout << max1 << " ";
                if ((j - 1) >= 0)
                    max1 = max(max1, dp[i - 1][j - 1]);
                if ((j + 1) < n)
                    max1 = max(max1, dp[i - 1][j + 1]);
                // cout << max1 << " ";
                dp[i][j] = max1 + matrix[i][j];
            }
        }
        // cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        //cout << dp[n - 1][i] << " ";
        ans = max(ans, dp[n - 1][i]);
    }
    //cout << endl;
    return ans;

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    //  Iterate over matrix
    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            //  Get maximum of all valid path
            matrix[row][col] = matrix[row][col] + max(matrix[row - 1][col], max(matrix[row - 1][max(0, col - 1)], matrix[row - 1][min(m - 1, col + 1)]));
        }
    }

    //  Get the max path sum
    int maxPathSum = INT_MIN;
    for (int col = 0; col < m; col++)
    {
        if (maxPathSum < matrix[n - 1][col])
        {
            maxPathSum = matrix[n - 1][col];
        }
    }
    return maxPathSum;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << getMaxPathSum(a) << endl;
    }

    return 0;
}
