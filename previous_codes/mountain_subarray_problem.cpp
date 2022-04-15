#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
public:
	vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
	                            int q) {
		// code here
		int left[n], right[n];
		int lastptr = 0;
		vector<bool> res;
		left[0] = lastptr;
		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i - 1])
				lastptr = i;
			left[i] = lastptr;
		}
		lastptr = n - 1;
		right[n - 1] = lastptr;
		for (int i = n - 2; i >= 0; i--)
		{
			if (a[i] > a[i + 1])
				lastptr = i;
			right[i] = lastptr;
		}
		for (int i = 0; i < q; i++)
		{
			res.push_back(right[queries[i].first] >= left[queries[i].second]);
		}
		return res;
	}
};

// { Driver Code Starts.

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, i, q;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> q;
		vector<pair<int, int>> queries(q);
		for (i = 0; i < q; i++) {
			cin >> queries[i].first >> queries[i].second;
		}
		Solution obj;
		auto v = obj.processQueries(a, n, queries, q);
		for (bool u : v) {
			cout << (u ? "Yes\n" : "No\n");
		}
	}
	return 0;
}  // } Driver Code Ends