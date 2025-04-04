#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int _max = *max_element(nums.begin(), nums.end());
        int count = 0, sum = 0;
        while (k--) {
            sum += (_max + count);
            count++;
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
        cout << ob.maximizeSum(a, k) << endl;
    }
    return 0;
}