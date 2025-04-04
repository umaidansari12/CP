class Solution {
public:
    vector<int> rearrangeArrayBrute(vector<int>& nums) {
        // 2 pass solution is to first store all pos and neg in an array and then rearrange them
        // 1 pass solution is to rearrange the array as we traverse, as we know even index will have pos and odd index will have neg elements
        vector<int> pos;
        vector<int> neg;
        int _size = nums.size();
        for (int i = 0; i < _size; i++) {
            if (nums[i] < 0) {
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }
        for (int i = 0; i < _size; i++) {
            if (i % 2 == 0)
                nums[i] = pos[i / 2];
            else
                nums[i] = neg[i / 2];
        }
        return nums;
    }
    vector<int> rearrangeArrayOptimal(vector<int>& nums) {
        int _size = nums.size(), pos_index = 0, neg_index = 1;
        vector<int> ans(_size, 0);
        for (int i = 0; i < _size; i++) {
            if (nums[i] >= 0) {
                ans[pos_index] = nums[i];
                pos_index += 2;
            }
            else {
                ans[neg_index] = nums[i];
                neg_index += 2;
            }
        }

        return ans;
    }
};

