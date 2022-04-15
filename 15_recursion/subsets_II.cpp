class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> r;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    r.push_back(nums[j]);
                }
            }
            sort(r.begin(), r.end());
            s.insert(r);
        }
        for (auto r : s)
            res.push_back(r);
        return res;
    }
}; 15_recursio