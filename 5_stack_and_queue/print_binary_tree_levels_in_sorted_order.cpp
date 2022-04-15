#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        // Your code here
        queue<int> q;
        int i = 0;
        q.push(arr[i++]);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> r;
            int size = q.size();
            while (size--) {
                r.push_back(q.front());
                q.pop();
                if (i < n) {
                    q.push(arr[i]);
                    i++;
                }
                if (i < n) {
                    q.push(arr[i]);
                    i++;
                }
            }
            sort(r.begin(), r.end());
            res.push_back(r);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;

        vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
        for (int i = 0; i < res.size(); ++i)
        {
            for (int j = 0; j < res[i].size(); ++j)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// Contributed By: Pranay Bansal  // } Driver Code Ends