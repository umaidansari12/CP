//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((arr[i] + arr[j]) == k)
                    count++;
            }
        }
        return count;
    }
    int getPairsCountTwoSum(int arr[], int n, int k) {
        // code here
        int count = 0;
        sort(arr, arr + n);
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == k)
            {
                count++;
                i++;
                j--;
            }
            else if (sum > k) {
                j--;
            }
            else {
                i++;
            }
        }
        return count;
    }
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (m.find(k - arr[i]) != m.end())
                count += m[k - arr[i]];
            m[arr[i]]++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}  // } Driver Code Ends