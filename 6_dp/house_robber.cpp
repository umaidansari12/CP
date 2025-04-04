#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int  helper(vector<int> &nums, int idx, int sum, int n, vector<int> &dp) {
        cout << idx << "-----" << sum << "----" << endl;
        if (idx == n)
            return sum;
        if (idx > n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = helper(nums, idx + 2, sum + nums[idx], n, dp);
        int non_pick = helper(nums, idx + 1, sum, n, dp);

        return dp[idx] = max(pick, non_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, 0, n, dp);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1)
//             return nums[0];
//         int dp[n];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for (int i = 2; i < n; i++)
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//         return dp[n - 1];
//     }
// };

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob = Solution();
        cout << ob.rob(a) << endl;
        cout << "done\n";
    }
    return 0;
}

/*
IP:
2
4
1 2 3 1
5
2 7 9 3 1

OP:
4
12

*/