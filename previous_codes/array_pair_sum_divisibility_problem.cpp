#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool canPair(vector<int> nums, int k) {
		int n = nums.size(), count 	 = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			for (int j = n / 2 ; j < n; j++)
				if ((nums[i] + nums[j]) % k == 0)
					count++;
		}

		return count == (n / 2) ? true : false;
	}
};



// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for (int i = 0; i < nums.size(); i++) cin >> nums[i];
		Solution ob;
		bool ans = ob.canPair(nums, k);
		if (ans)
			cout << "True\n";
		else
			cout << "False\n";
	}
	return 0;
}  // } Driver Code Ends