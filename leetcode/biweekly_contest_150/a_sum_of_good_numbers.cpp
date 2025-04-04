#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int _size = nums.size(), sum = 0;

        for (int i = 0; i < _size; i++) {
            bool good = true;
            if (((i - k) >= 0 and nums[i - k] >= nums[i]) or ((i + k) < _size and nums[i + k] >= nums[i])) {
                // cout << i << " " << nums[i] << endl;
                good = false;
            }
            if (good)
                sum += nums[i];
        }

        return sum;
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
        cout << ob.sumOfGoodNumbers(a, k) << endl;
    }
}