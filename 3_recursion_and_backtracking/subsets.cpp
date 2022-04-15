class Solution {
public:
    void solve(int idx, int n, vector<int>&nums, vector<vector<int>>&res, vector<int>r)
    {
        if (idx == n)
        {
            res.push_back(r);
            return;
        }
        r.push_back(nums[idx]);
        solve(idx + 1, n, nums, res, r);
        r.pop_back();
        solve(idx + 1, n, nums, res, r);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        solve(0, nums.size(), nums, res, r);
        return res;

    }
};