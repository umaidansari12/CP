class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index1 = n - 2;
        while (index1 >= 0 and nums[index1] >= nums[index1 + 1])
            index1--;
        if (index1 == -1)
            reverse(nums.begin(), nums.end());
        else {
            int index2 = n - 1;
            while (index2 > index1 and nums[index2] <= nums[index1]) {
                index2--;
            }

            swap(nums[index1], nums[index2]);

            reverse(nums.begin() + index1 + 1, nums.end());
        }

    }
};

#include<bits/stdc++.h>

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.

    int index1, index2;
    for (index1 = n - 2; index1 >= 0; index1--) {
        if (permutation[index1] < permutation[index1 + 1])
            break;
    }

    if (index1 >= 0) {
        for (index2 = n - 1; index2 > index1; index2--) {
            if (permutation[index2] > permutation[index1])
                break;
        }
        swap(permutation[index1], permutation[index2]);
    }
    reverse(permutation.begin() + index1 + 1, permutation.end());
    return permutation;
}