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

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, _size = nums.size();
        for (int i = 0; i < _size; i++) {
            if (farthest < i)
                return false;
            if (farthest == _size)
                return true;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};