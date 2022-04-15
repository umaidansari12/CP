#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int firstIndex(int a[], int n)
	{
		// Your code goes here'
		int ans = upper_bound(a, a + n, 0) - a;
		return (ans) == n ? -1 : ans;
	}
};

// { Driver Code Starts.
int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; i++) cin >> a[i];
		Solution ob;
		cout << ob.firstIndex(a, n) << endl;
	}
}  // } Driver Code End