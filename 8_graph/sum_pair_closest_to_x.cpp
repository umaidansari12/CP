//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
	vector<int> sumClosest(vector<int>arr, int x)
	{
		// code here
		int n = arr.size(), closest_diff = INT_MAX, ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int sum = arr[i] + arr[j];
				int diff = abs(sum - x);
				if (diff < closest_diff)
				{
					closest_diff = diff;
					ans1 = arr[i];
					ans2 = arr[j];
				}
				else if (diff == closest_diff)
				{
					closest_diff = diff;
					if ((ans1 + ans2) < sum)
					{
						ans1 = arr[i];
						ans2 = arr[j];
					}
				}
			}
		}
		return {ans1, ans2};
	}
	vector<int> sumClosest(vector<int>arr, int x)
	{
		// code here
		int n = arr.size(), closest_diff = INT_MAX, ans1 = 0, ans2 = 0, low = 0, high = n - 1;
		while (low < high)
		{
			int sum = arr[low] + arr[high];
			int diff = abs(sum - x);
			if (diff < closest_diff)
			{
				closest_diff = diff;
				ans1 = arr[low];
				ans2 = arr[high];
			}
			if (sum == x)
			{
				return {arr[low], arr[high]};
			}
			else if (sum < x)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		return {ans1, ans2};
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.sumClosest(arr, x);
		cout << ans[0] << " " << ans[1] << "\n";
	}
	return 0;
}  // } Driver Code Ends