

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	string minimum_Number(string s) {
		// Code here
		sort(s.begin(), s.end());
		int i = 0;
		while (i < s.size() && s[i] == '0')
			i++;
		if (i < s.size())
			swap(s[i], s[0]);
		return s;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		Solution ob;
		string ans = ob.minimum_Number(s);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends