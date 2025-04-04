class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, n = nums.size(), mid = n - n / 2, count = 0;
        for (int i = mid; i < n; i++) {
            if (2 * nums[start] <= nums[mid]) {
                count += 2;
                mid++;
                start++;
            }
            else {
                mid++;
            }
        }
        return count;
    }
};