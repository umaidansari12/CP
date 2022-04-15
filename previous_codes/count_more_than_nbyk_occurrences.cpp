// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find elements with count more than n/k times
// arr: input array
class Solution {
public:
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[i] == arr[j])
                    count++;
            }
            if (count > (n / k))
                ans++;
        }
        return ans;
    }
};

class Solution1 {
public:
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[arr[i]]++;
        for (auto i : m)
            if (i.second > (n / k))
                ans++;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends