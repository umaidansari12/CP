#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;

        //calling function maximizeTheCuts()
        cout << maximizeTheCuts(n, x, y, z) << endl;

    }

    return 0;
}// } Driver Code Ends


//Complete this function
int rodCutting(vector<pair<int, int>>&rd, int n, int w, int i, vector<vector<int>>&dp)
{
    if (i >= n)
        return 0;
    if (w == 0)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];
    if (rd[i].first <= w)
    {
        return (max(rd[i].second + rodCutting(rd, n, w - rd[i].first, i, dp), rodCutting(rd, n, w, i + 1, dp)));
    }
    else
    {
        return rodCutting(rd, n, w, i + 1, dp);
    }
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here

    /*vector<pair<int, int>> rd;
    rd.push_back(make_pair(x, 1));
    rd.push_back(make_pair(y, 1));
    rd.push_back(make_pair(z, 1));
    vector<vector<int>>dp(3, vector<int>(n + 1, -1));
    return rodCutting(rd, 3, n, 0, dp);*/
    vector<int>dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x]);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y]);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z]);
        if (dp[i] != -1)
            dp[i]++;
    }
    return max(dp[n], 0);
}