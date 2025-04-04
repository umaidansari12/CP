#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int max_len = 0;
            for (int j = 0; j < m; j++) {
                int len = 0, neg = 0, num = grid[j][i];
                if (num <= 0) {
                    neg = 1;
                    num = -num;
                    len++;
                }
                while (num > 0) {
                    len++;
                    num /= 10;
                }
                max_len = max(max_len, len);
                // cout << grid[i][j] << " ";
            }
            // cout << max_len << endl;

            ans[i] = max_len;
            // cout << endl;
        }
        // for(int i=0;)
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        Solution ob;
        vector<int> answer = ob.findColumnWidth(a);
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}