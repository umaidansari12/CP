
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
	int maxSortedAdjacentDiff(int* arr, int n) {
		// code here
		if (n < 2)
			return 0;
		sort(arr, arr + n);
		int ans = 0;
		for (int i = 0; i < n - 1; i++)
			ans = max(ans, arr[i + 1] - arr[i]);
		return ans;
	}
};

// { Driver Code Starts.
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return 0;
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i < n - 1; i++)
			res = max(res, nums[i + 1] - nums[i]);
		return res;

	}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob;
		auto ans = ob.maxSortedAdjacentDiff(a, n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends