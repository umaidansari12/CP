
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int  minimum_difference(vector<int>nums) {
        // Code here
        int n = nums.size(), diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            diff = min(diff, nums[i] - nums[i - 1]);
        }
        return diff;
    }
    int  minimum_difference(vector<int>nums) {
        // Code here
        int n = nums.size(), diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                diff = min(diff, abs(nums[i] - nums[j]));
            }
        }
        return diff;
    }
};

class Solution1 {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), m = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            m = min(m, arr[i + 1] - arr[i]);
        }
        vector<int> r(2, 0);
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; i++)
        {
            if ((arr[i + 1] - arr[i]) == m)
            {
                r[0] = arr[i];
                r[1] = arr[i + 1];
                res.push_back(r);
            }
        }
        return res;

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
        for (int i = 0; i < nums.size(); i++)cin >> nums[i];
        Solution ob;
        int ans = ob.minimum_difference(nums);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends