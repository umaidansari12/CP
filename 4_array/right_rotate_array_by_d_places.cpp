class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++)
        {
            pre[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++)
            nums[i] = pre[i];

    }
};
