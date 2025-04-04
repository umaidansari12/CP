#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    unordered_map<int, int> prefix_sum;
    long long sum = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == k)
            max_length = max(max_length, i + 1);
        if (prefix_sum.find(sum) == prefix_sum.end())
            prefix_sum[sum] = i;
        if (prefix_sum.find(sum - k) != prefix_sum.end())
            max_length = max(max_length, i - prefix_sum[sum - k]);
    }
    return max_length;
}

class Solution {
public:
    int lenOfLongSubarr(int A[],  int N, int K)
    {
        // Complete the function
        int max_length = 0;
        for (int i = 0; i < N; i++) {
            int sum = 0, length = 0;
            for (int j = i; j < N; j++) {
                sum += A[j];
                if (sum == K) {
                    length = j - i + 1;
                }
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }

};

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    long long sum = a[0];
    int max_length = 0, left = 0, right = 0;
    while (right < n) {
        while (left <= right and sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k)
            max_length = max(max_length, (right - left + 1));
        right++;
        if (right < n) {
            sum += a[right];
        }
    }

    return max_length;
}