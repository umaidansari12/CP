#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int sumOfMinAbsDifferences(int arr[], int n)
    {
        //code here.
        int sum = 0;

        // min absolute difference for
        // the 1st array element
        sort(arr, arr + n);
        sum += abs(arr[0] - arr[1]);

        // min absolute difference for
        // the last array element
        sum += abs(arr[n - 1] - arr[n - 2]);

        // find min absolute difference for rest of the
        // array elements and add them to sum
        for (int i = 1; i < n - 1; i++)
            sum += min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));

        // required sum
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        cout << ob.sumOfMinAbsDifferences(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends