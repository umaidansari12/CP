#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(arr[j]);
                if (s.size() <= 2) {
                    ans = max(ans, j - i + 1);
                    // cout << j << ":" << i << ":" << ans << endl;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob = Solution();
        cout << ob.totalElements(a) << endl;
    }
}