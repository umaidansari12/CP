// recursive solution

class Solution {
public:
    // the approach make use of recursion , in which we are trying every possible steps from 1 index to number of steps we can move from that index and checking if we are reaching to the last index through any of the current index
    bool solve(vector<int>nums, int index, int _size) {
        if (index >= nums.size() - 1)
            return true;
        bool ans = false;


        for (int steps = 1; steps <= min((int)nums.size(), nums[index]); steps++) {
            int new_index = index + steps;
            ans = ans or solve(nums, new_index, _size);
        }

        return ans;



    }
    bool canJump(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }
};

// greedy solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        // in this approach we are going to start from current index and take farthest steps and if some point of time , the farthest index is less than the current index that means in last iteration we have not taken any single step otherwise we would have move forward
        for (int index = 0; index < nums.size(); index++) {
            if (farthest < index)
                return false;
            farthest = max(farthest, index + nums[index]);
        }
        // checking if we have moved beyond the last index or not
        return farthest >= nums.size() - 1;
    }
};

// dp solution

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