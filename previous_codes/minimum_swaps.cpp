#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
public:
	//Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
		// Code here
		int n = nums.size(), ans = 0;
		pair<int, int> ap[n];
		for (int i = 0; i < n; i++)
		{
			ap[i].first = nums[i];
			ap[i].second = i;
		}
		sort(ap, ap + n);
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == true or i == ap[i].second)
			{
				continue;
			}
			int node = i, cycle = 0;
			while (!visited[node])
			{
				visited[node] = true;
				node = ap[node].second;
				cycle++;
			}
			ans += (cycle - 1);
		}
		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends