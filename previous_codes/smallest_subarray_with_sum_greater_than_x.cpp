

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:

    class Solution {
    public:

        int sbOptimalSlidingWindow(int arr[], int n, int x)
        {
            // Your code goes here
            int ans = INT_MAX, start = 0, end = 0, sum = 0;
            while (end < n)
            {
                while (sum <= x && end < n)
                    sum += arr[end++];
                while (sum > x && start < n)
                {
                    ans = min(ans, end - start);
                    sum -= arr[start++];
                }

            }
            return ans;
        }
    };

    int sb(int arr[], int n, int x)
    {
        // Your code goes here
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum > x)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }

            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
}  // } Driver Code Ends