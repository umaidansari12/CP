class Solution {
public:
    bool isPossible(int barrier, vector<int>&arr, int n, int m)
    {
        int allocatedStudent = 1, pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > barrier)
                return false;
            if (pages + arr[i] > barrier) // if pages crosses barrier
            {
                allocatedStudent++;
                pages = arr[i];
            }
            else
            {
                pages += arr[i];
            }
        }
        return allocatedStudent > m ? false : true;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *min_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0), mid, ans = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isPossible(mid, nums, nums.size(), m))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};