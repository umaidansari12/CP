#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            long long pro = 1;
            for (int j = i; j < n; j++)
            {
                pro *= a[j];
                if (pro >= k)
                    break;
                else
                    count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if (k == 0)
            return 0;
        int count = 0, left = 0;
        long long int prod = 1;
        for (int i = 0; i < n; i++)
        {
            prod *= a[i];
            while (prod >= k && left <= i)
                prod /= a[left++];
            count += (i - left + 1);
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends