class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long int sum = 0, ans = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum <= 0)
                return i;
        }
        return n;
    }
};