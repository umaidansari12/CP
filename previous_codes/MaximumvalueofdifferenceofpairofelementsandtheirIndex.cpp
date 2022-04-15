//Maximum value of difference of a pair of elements and their Index//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int maxValue(int arr[], int N) {
		// code here
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				ans = max(ans, abs(arr[i] - arr[j]) + abs(i - j));
			}
		}
		return ans;
	}
	int maxValue(int arr[], int N) {
		// code here
		int ans1 = 0, ans2 = 0, ma1 = 0, ma2 = 0, mi1 = INT_MAX, mi2 = INT_MAX;
		int a[N], b[N];
		for (int i = 0; i < N; i++)
		{
			a[i] = arr[i] - i;
			b[i] = arr[i] + i;
			ma1 = max(ma1, a[i]);
			ma2 = max(ma2, b[i]);
			mi1 = min(mi1, a[i]);
			mi2 = min(mi2, b[i]);
			ans1 = max(ans1, ma1 - mi1);
			ans2 = max(ans2, ma2 - mi2);
		}
		return max(ans1, ans2);
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;

		int arr[N];

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		Solution ob;
		cout << ob.maxValue(arr, N) << endl;
	}
	return 0;
}  // } Driver Code Ends