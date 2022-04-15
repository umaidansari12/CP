#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int n = A.size(), m = B.size(), o = C.size();
    int dp[n + 1][m + 1][o + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= o; k++)
            {
                if (i == 0 or j == 0 or k == 0)
                    dp[i][j][k] = 0;
                else
                {
                    if (A[i - 1] == B[j - 1] and A[i - 1] == C[k - 1])
                    {
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    }
                    else
                    {
                        dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                    }
                }
            }
        }
    }
    return dp[n][m][o];
}