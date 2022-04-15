#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:

    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n)
    {

        // Your code here
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] <= arr[j])
                    ans = max(ans, j - i);
            }
        }
        return ans;

    }

    int maxIndexDiff(int arr[], int n)
    {
        // Your code here
        int res = 0;
        vector<int> maxEnd(n, INT_MIN);
        maxEnd[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            maxEnd[i] = max(maxEnd[i + 1], arr[i]); //getting the decreasing array
        for (int i = 0; i < n; i++)
        {
            int low = i + 1, high = n - 1, ans = i;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (arr[i] <= maxEnd[mid])//applying binary search on the decereasing array checking the maximum index that can be the answer for current element
                {
                    ans = max(mid, i);
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            res = max(res, ans - i);
        }
        return res;
    }

    int maxIndexDiff(int arr[], int n)
    {

        // Your code here
        int Lmin[n], Rmax[n], ans = 0;
        Lmin[0] = arr[0];
        Rmax[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
            Lmin[i] = min(Lmin[i - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--)
            Rmax[i] = max(Rmax[i + 1], arr[i]);
        int i = 0, j = 0;
        while (j < n && i < n)
        {
            if (Lmin[i] <= Rmax[j])
            {
                ans = max(ans, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    //testcases
    cin >> T;
    while (T--) {
        int num;
        //size of array
        cin >> num;
        int arr[num];

        //inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        //calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;

    }
    return 0;
}   // } Driver Code Ends