#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        char S[N + 1];
        cin >> S;
        cout << CountPS(S, N) << endl;
    }
    return 0;
}

// } Driver Code Ends

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            count++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                count++;
            }
        }
        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < (n - k + 1); i++)
            {
                int j = (i + k - 1);
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};


int CountPS(char S[], int N)
{
    //code here
    int count = 0;
    bool dp[N][N];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++)
        dp[i][i] = true;
    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] == S[i + 1])
        {
            dp[i][i + 1] = true;
            count++;
        }
    }
    for (int k = 3; k <= N; k++)
    {
        for (int i = 0; i < (N - k + 1); i++)
        {
            int j = (i + k - 1);
            if (S[i] == S[j] and dp[i + 1][j - 1])
            {
                count++;
                dp[i][j] = true;
            }
        }
    }
    return count;


}