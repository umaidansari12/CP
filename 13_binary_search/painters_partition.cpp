#include <bits/stdc++.h>
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
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    return splitArray(boards, k);
}