#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
public:
    // function to find the triplet which sum to x
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for

    bool find3Numbers(int arr[], int N, int X)
    {
        //Your Code Here
        sort(arr, arr + N);
        for (int i = 0; i < N; i++)
        {
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                if (arr[i] + arr[l] + arr[r] == X)
                    return true;
                else if (arr[i] + arr[l] + arr[r] < X)
                    l++;
                else
                    r--;
            }
        }
        return false;
    }

    bool find3Numbers(int a[], int n, int s)
    {
        //Your Code Here
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i] + a[j] + a[k] == s)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool find3Numbers(int a[], int n, int s)
    {
        //Your Code Here
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (binary_search(a + j + 1, a + n, s - (a[i] + a[j])))
                    return true;
            }
        }

        return false;
    }


};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, sum;
        cin >> N >> sum;
        int i, A[N];
        for (i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        cout <<  ob.find3Numbers(A, N, sum) << endl;
    }
}
// } Driver Code Ends