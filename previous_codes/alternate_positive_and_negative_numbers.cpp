#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:

	void rearrange(int arr[], int n) {
		// code here
		vector<int> pos, neg;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= 0)
				pos.push_back(arr[i]);
			else
				neg.push_back(arr[i]);
		}
		int i = 0, j = 0, k = 0, p = pos.size(), ne = neg.size();
		while (i < n)
		{
			if (i % 2 == 0 && j < p)
			{
				arr[i++] = pos[j++];
			}
			else if (i % 2 == 0 && j >= p && k < ne)
			{
				arr[i++] = neg[k++];
			}
			if (i % 2 != 0 && k < ne)
			{
				arr[i++] = neg[k++];
			}
			else if (i % 2 != 0 && k >= ne && j < p)
			{
				arr[i++] = pos[j++];
			}
		}
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n;
		int arr[n];
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		ob.rearrange(arr, n);
		for (i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends