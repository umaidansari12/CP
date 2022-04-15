#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code
        int ans = -1, j = m, i = 0;
        while (i < n && j >= 0)
        {
            if (arr[i][j - 1] == 1)
            {
                j--;
                ans = i;
            }
            else
                i++;
        }
        return ans;

    }
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code
        int ans = -1, prev = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int c = count(arr[i].begin(), arr[i].end(), 1);
            if (c > prev)
            {
                prev = c;
                ans = i;
            }
        }
        return ans;

    }

    int rowWithMax1s(vector<vector<int> > a, int n, int m) {
        // code here
        //int ans=-1,prev=0;
        int ans = -1, prev = 0, r = a.size(), c = a[0].size();
        for (int i = 0; i < r; i++)
        {
            int n = 0;
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == 1)
                {
                    n = c - j;
                    break;
                }
            }
            if (prev < n)
            {
                prev = n;
                ans = i;
            }
        }
        return ans;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends