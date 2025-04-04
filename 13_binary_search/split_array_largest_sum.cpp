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

class Solution {
public:
    bool split_nums_into_k_possible_subarrays(vector<int> &nums, int subarray_size, int k) {
        int split = 1, subarray_sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (subarray_sum + nums[i] <= subarray_size) {
                subarray_sum += nums[i];
            }
            else {
                split++;
                subarray_sum = nums[i];
            }
        }
        return split <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()) , high = accumulate(nums.begin(), nums.end(), 0);
        // for(int _size = low; _size <= high; _size++){
        //     if(split_nums_into_k_possible_subarrays(nums, _size, k)){
        //         return _size;
        //     }
        // }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (split_nums_into_k_possible_subarrays(nums, mid, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};