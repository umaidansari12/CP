

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int lowerBound(int a[], int s, int e, int key)
    {
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (a[mid] == key)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (a[mid] < key)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return ans;
    }
    int upperBound(int a[], int s, int e, int key)
    {
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (a[mid] == key)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (a[mid] < key)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return ans;
    }
    int count(int arr[], int n, int x) {
        // code here
        int l = lowerBound(arr, 0, n - 1, x);
        int r = upperBound(arr, 0, n - 1, x);
        if (l == -1)
            return 0;
        return r - l + 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code End