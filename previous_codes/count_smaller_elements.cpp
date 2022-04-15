#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    void merge(int left, int mid, int right, vector<int>&count, vector<pair<int, int>>&v)
    {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right)
        {
            if (v[i].first <= v[j].first)
            {
                temp[k++] = v[j++];
            }
            else
            {
                count[v[i].second] += (right - j + 1);
                temp[k++] = v[i++];
            }
        }
        while (i <= mid)
            temp[k++] = v[i++];
        while (j <= right)
            temp[k++] = v[j++];
        for (i = left; i <= right; i++)
            v[i] = temp[i - left];
    }
    void mergeSort(int left, int right, vector<int>&count, vector<pair<int, int>>&v)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid, count, v);
        mergeSort(mid + 1, right, count, v);
        merge(left, mid, right, count, v);
    }
    vector<int> constructLowerArray(int *arr, int n) {
        vector<int> count(n, 0);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = make_pair(arr[i], i);
        }
        mergeSort(0, n - 1, count, v);
        return count;

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends