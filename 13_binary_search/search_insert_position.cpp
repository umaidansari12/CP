class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, target_index = -1, mid = (start+end)/2;

        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid+1;
                target_index = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
                target_index = mid;
            }
        }

        return target_index;
        
    }
};


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();

    }
};
