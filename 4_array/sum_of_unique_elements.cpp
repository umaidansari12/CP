class Solution {
public:
    int sumOfUniqueBetter(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int _size = nums.size();
        for (int i = 0; i < _size; i++)
            hashmap[nums[i]]++;
        int sum = 0;
        for (int i = 0; i < _size; i++)
        {
            if (hashmap[nums[i]] == 1)
                sum += nums[i];
        }

        return sum;

    }
    int sumOfUniqueBrute(vector<int>& nums) {
        int _size = nums.size(), sum = 0;
        for (int i = 0; i < _size; i++) {
            bool found = false;
            for (int j = 0; j < _size; j++) {
                if (i != j and nums[j] == nums[i]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                sum += nums[i];
        }
        return sum;
    }
    int sumOfUniqueOptimal(vector<int>& nums) {
        vector<int> count(101, 0);
        int _size = nums.size(), sum = 0;
        for (int i = 0; i < _size; i++) {
            if (count[nums[i]] == 0) {
                count[nums[i]]++;
                sum += nums[i];
            }
            else if (count[nums[i]] == 1) {
                count[nums[i]] = -1;
                sum -= nums[i];
            }
        }
        return sum;
    }
};

