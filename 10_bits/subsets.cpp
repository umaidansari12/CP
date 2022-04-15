class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        //to store the results
        // we take binary representation of every number and then check if every bit of the number from 0 to n-1 is set or not if it is set we will include that indexed element into our resultant array else we will not include the element
        int n = nums.size();
        //generating numbers from 0 to n-1
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> r;
            for (int j = 0; j < n; j++)
            {
                //checking for every number if the bit from 0 to n-1 is set or not
                if (i & (1 << j))
                    r.push_back(nums[j]);
            }
            res.push_back(r);
        }
        return res;
    }
};