#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int minValueToBalance(int a[], int n)
	{
		//code here.
		int sum1 = accumulate(a, a + ((n / 2)), 0);
		int sum2 = accumulate(a + (n / 2), a + n, 0);
		return abs(sum1 - sum2);
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
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		Solution ob;
		cout << ob.minValueToBalance(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends