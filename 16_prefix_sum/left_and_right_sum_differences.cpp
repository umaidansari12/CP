class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int num_len = nums.size();
        vector<int> leftSum(num_len, 0), rightSum(num_len, 0), answer(num_len, 0);
        leftSum[0] = 0;
        rightSum[num_len - 1] = 0;
        for (int i = 1; i < num_len; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            rightSum[num_len - i - 1] = rightSum[num_len - i] + nums[num_len - i];
        }

        for (int i = 0; i < num_len; i++) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;

    }
};