//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function template for C++



class Solution {
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        int left = 0, right = 0, l = 0, r = arr.size() - 1, minDiff = INT_MAX;
        while (l < r)
        {
            int sum = arr[l] + arr[r];
            int diff = abs(sum - x);
            if (diff < minDiff)
            {
                minDiff = diff;
                left = arr[l];
                right = arr[r];
            }
            if (sum == x)
            {
                left = arr[l];
                right = arr[r];
                l++;
                r--;
                vector<int> res;
                res.push_back(left);
                res.push_back(right);
                return res;
            }
            else if (sum < x)
                l++;
            else
                r--;
        }
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends