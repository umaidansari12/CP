#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDigit(int num) {
        int max_digit = -1;
        while (num != 0) {
            max_digit = max(max_digit, num % 10);
            num /= 10;
        }
        return max_digit;
    }

    int maxSum(vector<int>& nums) {
        unordered_map<int, vector<int>> max_digit_map;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int max_digit = maxDigit(nums[i]);
            max_digit_map[max_digit].push_back(nums[i]);
        }

        int max_pair_sum = -1;

        for (auto i : max_digit_map) {
            int sum = -1;
            int _size = i.second.size();
            sort(i.second.begin(), i.second.end());

            for (int j = 1; j < _size; j++) {
                // cout << i.second[j] << " " << i.second[j - 1] << endl;
                sum = (i.second[j] + i.second[j - 1]);
                // cout << sum << endl;
                max_pair_sum = max(sum, max_pair_sum);
            }

        }
        return max_pair_sum;
    }

};


int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution ob = Solution();
        cout << ob.maxSum(nums) << endl;
    }

    return 0;
}

/*
- given 0 indexed integer array nums
- find the maximum pair of numbers from nums such that maximum digit in both numbers are equal
- return maximum sum or -1 if no such pairs exists

- solution
    - the answer will exist only if the reversal of number exists
    - hash every number on the basis of max digit
    - visit every number, find max digit, hash number on the basis of max digit
    - traverse the hash and find max pair sum before that sort every number max will come close that way


*/