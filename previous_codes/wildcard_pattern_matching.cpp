#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = p.size() + 1, m = s.size() + 1;
    bool dp[n][m];
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (i == n - 1 && j == m - 1)
          dp[i][j] = true;
        else if (i == n - 1)
          dp[i][j] = false;
        else if (j == m - 1)
        {
          if (p[i] == '*')
            dp[i][j] = dp[i + 1][j];
          else
            dp[i][j] = false;
        }
        else
        {
          if (p[i] == '?')
            dp[i][j] = dp[i + 1][j + 1];
          else if (p[i] == '*')
            dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
          else if (p[i] == s[j])
            dp[i][j] = dp[i + 1][j + 1];
          else
            dp[i][j] = false;
        }
      }
    }
    return dp[0][0];

  }
};


class Solution {
public:
  /*You are required to complete this method*/
  int wildCard(string pattern, string str)
  {
    int n = pattern.size() + 1, m = str.size() + 1;
    int dp[n][m];
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (i == n - 1 && j == m - 1)
          dp[i][j] = 1;
        else if (i == n - 1)
          dp[i][j] = 0;
        else if (j == m - 1)
        {
          if (pattern[i] == '*')
          {
            dp[i][j] = dp[i + 1][j];
          }
          else
            dp[i][j] = 0;
        }
        else
        {
          if (pattern[i] == '?')
          {
            dp[i][j] = dp[i + 1][j + 1];
          }
          else if (pattern[i] == '*')
          {
            dp[i][j] = (dp[i][j + 1] || dp[i + 1][j]);
          }
          else if (pattern[i] == str[j])
          {
            dp[i][j] = dp[i + 1][j + 1];
          }
          else
            dp[i][j] = 0;
        }
      }
    }
    return dp[0][0];

  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string pat, text;
    cin >> pat;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> text;
    Solution obj;
    cout << obj.wildCard(pat, text) << endl;
  }
}
// } Driver Code Ends