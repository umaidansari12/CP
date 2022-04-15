class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> p;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            p.push(nums[i]);
        k--;
        while (k--)
            p.pop();
        return p.top();

    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];

    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < nums.size(); i++)
        {
            if (p.size() == k)
            {
                if (p.top() < nums[i])
                {
                    p.pop();
                    p.push(nums[i]);
                }
            }
            else if (p.size() < k)
                p.push(nums[i]);
        }
        return p.top();
    }
};