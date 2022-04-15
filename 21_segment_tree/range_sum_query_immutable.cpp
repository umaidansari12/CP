class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        a = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++)
            sum += a[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
class NumArray {
public:
    vector<int> a, pre;
    NumArray(vector<int>& nums) {
        a = nums;
        pre = nums;
        pre[0] = a[0];
        for (int i = 1; i < a.size(); i++)
            pre[i] = pre[i - 1] + a[i];
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return pre[right];
        return pre[right] - pre[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */