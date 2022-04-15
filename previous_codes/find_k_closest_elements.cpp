//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int binarySearch(vector<int> arr, int low, int high, int x)
    {
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] == x)
                return mid;
            else if (x < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return x < arr[mid] ? mid - 1 : mid;
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int> res;
        int l = binarySearch(arr, 0, n - 1, x);
        int r = l + 1;
        while (l >= 0 and arr[l] == x)
            l--;
        while (r < n and arr[r] == x)
            r++;
        while (k > 0 and (l >= 0 or r < n))
        {
            if (l >= 0 and r < n)
            {
                if (x - arr[l] < arr[r] - x)
                    res.push_back(arr[l--]);
                else
                    res.push_back(arr[r++]);
            }
            else if (l >= 0)
                res.push_back(arr[l--]);
            else
                res.push_back(arr[r++]);
            k--;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends