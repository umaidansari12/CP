#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	string printMinIndexChar(string S, string patt)
	{
		// Code here
		map<char, int> m;
		for (int i = 0; i < S.size(); i++)
		{
			char ch = S[i];
			if (m.find(ch) == m.end())
			{
				m[ch] = i;
			}
		}
		int index = S.size();
		string ans = "$";
		for (auto ch : patt)
		{
			if (m.find(ch) != m.end() and index > m[ch])
			{
				index = m[ch];
				ans = ch;
			}
		}
		return ans;
	}
	int minIndexChar(string str, string patt)
	{
		// Your code here
		int ans = INT_MAX;
		unordered_map<char, int> m;
		for (int i = 0; i < str.size(); i++) {
			if (m.find(str[i]) == m.end())
			{
				m[str[i]] = i;
			}
		}
		for (auto i : patt) {
			if (m.find(i) != m.end())
				ans = min(ans, m[i]);
		}
		if (ans == INT_MAX)
			return -1;
		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;
		string patt;
		cin >> patt;
		Solution obj;
		cout << obj.printMinIndexChar(str, patt) << endl;
	}

	return 0;
}  // } Driver Code Ends