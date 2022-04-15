/*Problem Description

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.


Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.


Output Format
 Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



Example Input
Input:1

 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2

 A = 1
 B = 4
 C = ["LLLL"]


Example Output
Output-1 :

 1
Output-2 :

 3


Example Explanation*
Explanation for Input-1:

 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:

 Matrix looks like: LLLL
 We go right three times.
*/


bool isValid(int x, int y, int m, int n) {
    if (x >= 0 && y >= 0 && x < m && y < n)
        return true;
    return false;
}
int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<int>> dp(A, vector(B, INT_MAX));
    dp[A - 1][B - 1] = 0;
    vector<char> d = {'U', 'D', 'L', 'R'};
    vector dx{ -1, 1, 0, 0};
    vector dy{0, 0, -1, 1};
    int nx, ny, prior, cost, i, j;
    bool change = true;
    queue<pair<int, int>>q;
    q.push({A - 1, B - 1});
    pair<int, int> p;
    while (!q.empty()) {
        p = q.front(); q.pop();
        i = p.first; j = p.second;
        for (int k = 0; k < 4; k++) {
            nx = i - dx[k];
            ny = j - dy[k];
            if (!isValid(nx, ny, A, B)) continue;
            cost = (C[nx][ny] == d[k]) ? 0 : 1;
            if (cost + dp[i][j] < dp[nx][ny]) {
                dp[nx][ny] = cost + dp[i][j];
                q.push({nx, ny});
            }
        }
    }

    return dp[0][0];
}
