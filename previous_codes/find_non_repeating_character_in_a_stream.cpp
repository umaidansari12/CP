#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	string FirstNonRepeating(string A) {
		// Code
		queue<char> q;
		string s;
		int count[26] = {0};
		for (auto ch : A)
		{
			q.push(ch);
			count[ch - 'a']++;
			while (!q.empty())
			{
				if (count[q.front() - 'a'] > 1)
					q.pop();
				else
				{
					s += q.front();
					break;
				}
			}
			if (q.empty())
				s += '#';
		}
		return s;
	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends