#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
	string findSubString(string s)
	{
		// Your code goes here
		int cnt[256] = {0}, cnt1[256] = {0}, count = 0, count1 = 0, start = 0, window_len = 0, min_window_len = INT_MAX, start_idx = -1;
		for (int i = 0; i < s.length(); i++)
		{
			cnt[s[i]]++;
			if (cnt[s[i]] == 1)
				count++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			cnt1[s[i]]++;
			if (cnt[s[i]] != 0 && cnt1[s[i]] == 1)
				count1++;
			if (count == count1)
			{
				while (cnt1[s[start]] > 1)
				{
					cnt1[s[start++]]--;
				}
				window_len = i - start + 1;
				if (window_len < min_window_len)
				{
					min_window_len = window_len;
					start_idx = start;
				}
			}
			//cout << count1 << endl;
		}
		//cout << count << endl;
		return s.substr(start_idx, min_window_len);
	}

	string findSubStringBrute(string s)
	{
		// Your code goes here
		unordered_map<char, int> m;
		for (int i = 0; i < s.size(); i++)
			m[s[i]]++;
		//cout << m.size() << endl;
		int min_window_len = INT_MAX, window_len = 0, start = -1;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				unordered_map<char, int> m1;
				window_len = j - i + 1;
				string s2 = s.substr(i, j - i + 1);

				for (int k = 0; k < s2.size(); k++)
					m1[s2[k]]++;
				if (m.size() == m1.size())
				{
					if (min_window_len > window_len)
					{
						min_window_len = window_len;
						start = i;
					}
				}
			}
		}
		return s.substr(start, min_window_len);
	}
};

// { Driver Code Starts.
// Driver code
int main() {
	int t;
	cin >> t;
	while (t--) {

		string str;
		cin >> str;
		Solution ob;
		cout << ob.findSubString(str).size() << endl;
	}
	return 0;
}  // } Driver Code Ends