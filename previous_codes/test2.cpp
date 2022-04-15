#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

public:
	vector<int> downwardDigonal(int n, int m, vector<vector<int>> a)
	{
		// Your code goes here
		vector<int> res;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (flag)
			{
				int j = 0, k = i;
				while (j < m && k >= 0)
				{
					res.push_back(a[j++][k--]);
				}
				flag = 0;
			}
			else
			{
				int j = 0, k = i;
				vector<int> r;
				while (j < m && k >= 0)
				{
					r.push_back(a[j++][k--]);
				}
				for (int i = r.size() - 1; i >= 0; i--)
					res.push_back(r[i]);
				flag = 1;
			}
		}
		for (int j = 1; j < m; j++)
		{
			if (flag)
			{
				int row = j, col = n - 1;
				while (row < m && col >= 0)
				{
					res.push_back(a[row++][col--]);
				}
				flag = 0;
			}
			else
			{
				int row = j, col = n - 1;
				vector<int> r;
				while (row < m && col >= 0)
				{
					r.push_back(a[row++][col--]);
				}
				for (int i = r.size() - 1; i >= 0; i--)
					res.push_back(r[i]);
				flag = 1;
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
		int n, m;
		cin >> m >> n;

		vector<vector<int>> A(m, vector<int>(n));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> A[i][j];

		Solution obj;
		vector<int> ans = obj.downwardDigonal(n, m, A);

		for (auto i : ans)
			cout << i << " ";

		cout << "\n";
	}

	return 0;
}
// } Driver Code Ends