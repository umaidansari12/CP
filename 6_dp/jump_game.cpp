class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if the given array is of size less than 1 that means we can move to last index as both starting and ending index are same
        if (nums.size() <= 1)
            return true;

        // if starting point max reachable steps are 0 that means we can not take any steps from the starting point
        if (nums[0] == 0)
            return false;

        // dp[i] means if the ith index is reachable or not dp[i] = true means reachable
        vector<bool> dp(nums.size(), false);

        // starting point is always reachable
        dp[0] = true;

        // we check for index other than starting point whether they are reachable or not by starting from 0th index moving till (i-1)th index by taking max steps on every jth index check if jth index is reachable and j+steps[j]>=i that means if we take steps[j] then if we can reach i or not if we can reach that means i is also reachable so setting it to reachable
        for (int index = 1; index < nums.size(); index++) {
            for (int curr_index = 0; curr_index < index; curr_index++) {
                if (dp[curr_index] and curr_index + nums[curr_index] >= index) {
                    dp[index] = true;
                    break;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};