#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<string> AllPossibleStrings(string s) {
		// Code here
		vector<string> res;
		int n = s.size();
		for (int num = 0; num < (1 << n); num++)
		{
			string r;
			for (int i = 0; i < n; i++)
			{
				if (num & (1 << i))
					r += s[i];
			}
			if (r.size() > 0)
				res.push_back(r);
		}
		sort(res.begin(), res.end());
		return res;
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
		vector<string> res = ob.AllPossibleStrings(s);
		for (auto i : res)
			cout << i << " ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends