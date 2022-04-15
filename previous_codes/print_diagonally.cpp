#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		// Your code goes here
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			int j = 0, k = i;
			while (j < n && k >= 0)
			{
				res.push_back(a[j++][k--]);
			}
		}
		for (int j = 1; j < n; j++)
		{
			int row = j, col = n - 1;
			while (row < n && col >= 0)
			{
				res.push_back(a[row++][col--]);
			}
		}
		return res;
	}

};

// { Driver Code Starts.



int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<vector<int>> A(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> A[i][j];

		Solution obj;
		vector<int> ans = obj.downwardDigonal(n, A);

		for (auto i : ans)
			cout << i << " ";

		cout << "\n";
	}

	return 0;
}
// } Driver Code Ends