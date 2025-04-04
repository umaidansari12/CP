class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        int low = 1, high = n - 2, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid - 1]<nums[mid] and nums[mid]>nums[mid + 1])
                return mid;
            if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1])
                return i;
        }
        if (nums[n - 2] < nums[n - 1])
            return n - 1;
        // if(nums[0]<nums[1])
        //     return 1;

        return 0;
    }
};

