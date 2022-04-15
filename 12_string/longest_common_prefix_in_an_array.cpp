//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:

	string longestCommonPrefix (string arr[], int N)
	{
		// your code here
		int _min = INT_MAX;
		for (int i = 0; i < N; i++) {
			_min = min(_min, (int)arr[i].size());
		}

		string res;

		for (int i = 0; i < _min; i++) {
			bool found = true;
			for (int j = 1; j < N; j++) {
				if (arr[0][i] != arr[j][i]) {
					found = false;
					break;
				}
			}
			if (found)
				res += arr[0][i];
			else
				break;
		}
		if (res.size() == 0)
			return "-1";
		return res;
	}
	string longestCommonPrefixUtil(string a, string b) {
		int n1 = a.size(), n2 = b.size();
		string res;
		for (int i = 0, j = 0; i < n1 and j < n2; i++, j++) {
			if (a[i] != b[j])
				break;
			res += a[i];
		}
		return res;
	}

	string longestCommonPrefix (string arr[], int N)
	{
		// your code here
		string prefix = arr[0];
		for (int i = 1; i < N; i++) {
			prefix = longestCommonPrefixUtil(prefix, arr[i]);
		}

		if (prefix.size() == 0)
			return "-1";
		return prefix;
	}
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		Solution ob;
		cout << ob.longestCommonPrefix (arr, n) << endl;
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends