#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int CountWays(string s) {
		// Code here
		int n = s.size();
		vector<int> dp(n, 0);
		dp[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (s[i - 1] == '0' and s[i] == '0')
			{
				dp[i] = 0;
			}
			else if (s[i - 1] == '0' and s[i] != '0')
			{
				dp[i] = dp[i - 1];
			}
			else if (s[i - 1] != '0' and s[i] == '0')
			{
				if (s[i - 1] == '1' or s[i - 1] == '2')
				{
					dp[i] = (i >= 2) ? dp[i - 2] : 1;
				}
				else
				{
					dp[i] = 0;
				}
			}
			else
			{
				int a = (s[i - 1] - '0') * 10 + (s[i] - '0');
				cout << a << endl;
				if (a <= 26)
				{
					dp[i] = dp[i - 1] + (i >= 2) ? dp[i - 2] : 1;
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
		}
		return dp[n - 1];
	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends