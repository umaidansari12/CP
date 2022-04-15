class Solution {
public:
    int maxSubarraySum(int arr[], int N) {
        // Your code here
        int curr_sum = 0, max_sum = 0;
        for (int i = 0; i < N; i++)
        {
            curr_sum += arr[i];
            max_sum = max(curr_sum, max_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }
        return max_sum;
    }
};

//Let maximum sum of all subarrays ending at ith position be mx[i], then mx[i] = max(0,mx[i-1] + a[i])

class Solution {
public:
    int maxSubarraySum(int a[], int n) {

        long long maxh = 0, maxf = INT_MIN;

        for (int i = 0; i < n; i++) //iterating over array
        {
            maxh += a[i];
            maxf = max(maxh, maxf); //Seeing if adding current element increases the sum of not

            // check at any index, if maxh is negative
            // if it becomes negative, then make it 0 again
            if (maxh < 0)
                maxh = 0;

        }
        return maxf;

    }
};