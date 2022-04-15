#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {


public:
	int findMax(int n, int m, int a[], int b[], int k[])
	{
		// Your code goes here
		int count[n + 1] = {0};
		for (int i = 0; i < m; i++)
		{
			count[a[i]] += k[i];
			count[b[i] + 1] -= k[i];
		}
		int ans = count[0];
		for (int i = 1; i <= n; i++)
		{
			count[i] += count[i - 1];
			ans = max(ans, count[i]);
		}
		return ans;
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
		cin >> n >> m;
		int a[m], b[m], k[m];
		for (int i = 0; i < m; i++)
		{
			cin >> a[i] >> b[i] >> k[i];
		}


		Solution ob;
		cout <<  ob.findMax(n, m, a, b, k);
		cout << "\n";

	}
	return 0;
}



// } Driver Code Ends