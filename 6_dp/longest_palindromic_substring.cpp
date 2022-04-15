#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size(), maxLength = 1, start = 0;
		bool dp[n][n];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = true;
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				dp[i][i + 1] = true;
				if (maxLength < 2)
				{
					start = i;
					maxLength = 2;
				}
			}

		}
		for (int k = 3; k <= n; k++)
		{
			for (int i = 0; i < (n - k + 1); i++)
			{
				int j = i + k - 1;
				if (s[i] == s[j] and dp[i + 1][j - 1])
				{
					dp[i][j] = true;
					if (maxLength < k)
					{
						start = i;
						maxLength = k;
					}
				}
			}
		}
		return s.substr(start, maxLength);
	}
};

// } Driver Code Ends
class Solution {
public:
	string longestPalinBottomUp (string S) {
		// code here
		int n = S.size(), start = -1;
		bool dp[n][n];
		memset(dp, 0, sizeof(dp));
		int maxLength = 1;
		for (int i = 0; i < n; i++)
			dp[i][i] = true; //filling for diagonal (start,end)->(i,i) substring starting
		//at index i and ending at index i means a 1 length string and which is always
		// a palindrome
		for (int i = 0; i < n - 1; i++)
		{
			if (S[i] == S[i + 1])
			{
				dp[i][i + 1] = true;
				//filling for 2 length (start,end)->(i,i+1) substring starting
				//at index i and ending at index i+1 means a 2 length string and check
				//if the next character is equal then it is
				// a palindrome
				if (maxLength < 2)
				{
					start = i;
					maxLength = 2;
				}
			}
		}
		//now checking our condition for len>=3 where
		// check boundary element are equal and
		// check if non boundary string are queal by checking dp[i+1][j-1] is true or not
		for (int k = 3; k <= n; k++)
		{
			for (int i = 0; i < n - k + 1; i++)
			{
				int j = i + k - 1;
				if (S[i] == S[j] and dp[i + 1][j - 1])
				{
					dp[i][j] = true;
					if (maxLength < k)
					{
						start = i;
						maxLength = k;
					}
				}
			}
		}
		return S.substr(start, maxLength);
	}
	bool isPalindrome(string s)
	{
		string rev = s;
		reverse(s.begin(), s.end());
		return rev == s;
	}

	string longestPalindrome(string s)
	{
		/*for (int i = 0; i < s.length(); i++)
		{
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[i] == s[j])
			{
				int k = i, m = j;
				while (k < m)
				{
					if (s[k] != s[m])
						break;
				}
			}
		}
		}*/
		int mx = 0, start = -1;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				//
				int flag = 1;
				for (int k = 0; k < (j - i + 1) / 2; k++)
				{
					if (s[i + k] != s[j - k])
						flag = 0;
				}
				if (flag && (j - i + 1) > mx)
				{
					//cout << i << " " << j << endl;
					start = i;
					mx = j - i + 1;
				}
			}
		}
		for (int i = start; i <= (start + mx) - 1; i++)
			cout << s[i];
		cout << endl;
	}

	string longestPalin (string s) {
		// code here
		int ans = 0, n = s.size(), start = -1;
		for (int i = 0; i < n; i++)
		{
			string temp;
			for (int j = i; j < n; j++)
			{
				temp += s[j];
				//cout << temp << endl;
				if (isPalindrome(temp))
				{
					int n = temp.size();
					if (ans < n)
					{
						ans = n;
						start = i;
					}
				}
			}
		}
		return s.substr(start, ans);
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string S; cin >> S;

		Solution ob;
		cout << ob.longestPalin (S) << endl;
	}
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		/*for (int i = 0; i < s.length(); i++)
		{
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[i] == s[j])
				{
					int k = i, m = j;
					while (k < m)
					{
						if (s[k] != s[m])
							break;
					}
				}
			}
		}*/
		int mx = 0, start = -1;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				//
				int flag = 1;
				for (int k = 0; k < (j - i + 1) / 2; k++)
				{
					if (s[i + k] != s[j - k])
						flag = 0;
				}
				if (flag && (j - i + 1) > mx)
				{
					//cout << i << " " << j << endl;
					start = i;
					mx = j - i + 1;
				}
			}
		}
		for (int i = start; i <= (start + mx) - 1; i++)
			cout << s[i];
		cout << endl;
	}


	return 0;
}