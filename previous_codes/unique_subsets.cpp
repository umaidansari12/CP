#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
public:
	//Function to find all possible unique subsets.
	vector<vector<int> > AllSubsets(vector<int> arr, int n)
	{
		// code here
		vector<vector<int>> res;
		set<vector<int>> s;
		res.push_back({});
		sort(arr.begin(), arr.end());
		for (int i = 1; i < (1 << n); i++)
		{
			vector<int> r;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					r.push_back(arr[j]);
				}
			}
			//sort(r.begin(),r.end());
			s.insert(r);
		}
		for (auto i : s)
			res.push_back(i);
		return res;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> A;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			A.push_back(x);
		}
		Solution obj;
		vector<vector<int> > result = obj.AllSubsets(A, n);
		// printing the output
		for (int i = 0; i < result.size(); i++) {
			cout << '(';
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j];
				if (j < result[i].size() - 1)
					cout << " ";
			}
			cout << ")";
		}
		cout << "\n";
	}
}


// } Driver Code Ends