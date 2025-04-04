class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int _size = nums.size(), max_len = 0;
        for (int i = 0; i < _size; i++) {
            int count_1s = 0;
            for (int j = i; j < _size; j++) {
                int len = j - i + 1;
                count_1s += nums[j];
                if ((len - count_1s) <= k) {
                    max_len = max(max_len, len);
                }
                else {
                    break;
                }
            }
        }
        return max_len;
    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int _size = nums.size(), max_len = 0, count_1s = 0, left = 0, right = 0;
        while (right < _size) {
            count_1s += nums[right];
            int current_len = right - left + 1;
            if ((current_len) - count_1s <= k) {
                max_len = max(max_len, current_len);
            }
            else {
                count_1s -= nums[left];
                left++;
            }
            right++;
        }
        return max_len;
    }
};

