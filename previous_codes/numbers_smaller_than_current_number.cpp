class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> r, count(101, 0);
        for (int i = 0; i < n; i++)
        {
            count[nums[i]]++;
        }
        for (int i = 1; i < 101; i++)
            count[i] += count[i - 1];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                r.push_back(0);
            else
                r.push_back(count[nums[i] - 1]);
        }
        return r;

    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> r;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i && nums[j] < nums[i])
                    count++;
            }
            r.push_back(count);
        }
        return r;

    }
};