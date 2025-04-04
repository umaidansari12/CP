#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];
        long long answer = 0;
        if (median == k)
            return answer;
        else if (median > k) {
            for (int i = n / 2; i >= 0; i--) {
                if (nums[i] > k) {
                    answer += (nums[i] - k);
                }
            }
        }
        else if (median < k) {
            for (int i = n / 2; i < n; i++) {
                if (nums[i] < k) {
                    answer += (k - nums[i]);
                }
            }
        }
        return answer;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob = Solution();
        cout << ob.minOperationsToMakeMedianK(a, k) << endl;
    }
}