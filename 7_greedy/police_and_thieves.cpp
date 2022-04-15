//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int catchThieves(char arr[], int n, int k)
	{
		// Code here
		int cnt = 0;
		bool visited[n] = {false};
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 'P')
			{
				int j = i, flag = 0;
				while (j >= 0)
				{
					if (!visited[j] and arr[j] == 'T')
					{
						visited[j] = true;
						cnt++;
						flag = 1;
						break;
					}
					j--;
				}
				if (!flag)
				{
					while (j < n)
					{
						if (!visited[j] and arr[j] == 'T')
						{
							visited[j] = true;
							cnt++;
							flag = 1;
							break;
						}
						j++;
					}
				}
			}
		}
		return cnt;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		Solution obj;
		cout << obj.catchThieves(arr, n, k) << endl;
	}
	return 0;
}

// } Driver Code Ends