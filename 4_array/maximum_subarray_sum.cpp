class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                ans = max(ans, sum);
            }
        }

        return ans;

    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }

        return ans;
    }
};

O(N ^ 3) Solution

int maxSubArray(vector < int > & nums, vector < int > & subarray) {
    int max_sum = 0;
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    int i, j;
    for (i = 0; i <= n - 1; i++) {
        for (j = i; j <= n - 1; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum = sum + nums[k];
            if (sum > max_sum) {
                subarray.clear();
                max_sum = sum;
                subarray.push_back(i);
                subarray.push_back(j);

            }
        }
    }
    return max_sum;
}

int maxSubArray(vector < int > & nums, vector < int > & subarray) {
    int msf = nums[0], meh = 0;
    int s = 0;
    for (int i = 0; i < nums.size(); i++) {
        meh += nums[i];
        if (meh > msf) {
            subarray.clear();
            msf = meh;
            subarray.push_back(s);
            subarray.push_back(i);

        }
        if (meh < 0) {
            meh = 0;
            s = i + 1;

        }
    }

    return msf;
}