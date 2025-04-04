class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), length = 0, max_length = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (i == 0 or nums[i - 1] == 0) {
                    length = 1;
                }
                else
                    length++;
            }
            max_length = max(length, max_length);
        }
        return max_length;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), length = 0, max_length = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                length++;
            }
            else
                length = 0;
            max_length = max(length, max_length);
        }
        return max_length;
    }
};