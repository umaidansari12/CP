#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0), conver(n, 0);
        int _max = 0;
        for (int i = 0; i < n; i++) {
            _max = max(nums[i], _max);
            // int _max = 0;
            // for (int j = 0; j <= i; j++) {
            //     _max = max(nums[j], _max);
            // }
            conver[i] = nums[i] + _max;
        }
        for (int i = 1; i < n; i++) {
            conver[i] = conver[i] + conver[i - 1];
        }
        return conver;
    }
};

// 0 1 2 3 4

// 2 3 7 5 10

// n = 5

// conver
// 4 6 14 12 20
// 4 10 24 36 56

// _max = 2

// i = 0,1,2,3,4

// 2,0 -> 2
// 3,2 -> 3
// 7,3 -> 7
// 5,7 -> 7
// 10,7 -> 10




int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        Solution ob;
        vector<long long> answer = ob.findPrefixScore(a);
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}