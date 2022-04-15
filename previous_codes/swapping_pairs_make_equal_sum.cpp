#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        // Your code goes here
        int sum1 = accumulate(A, A + n, 0);
        int sum2 = accumulate(B, B + m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((sum1 - A[i] + B[j]) == (sum2 - B[j] + A[i]))
                    return 1;
            }
        }
        return -1;
    }


};

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    int findSwapValues(int A[], int n, int B[], int m)
    {
        // Your code goes here
        int sum1 = accumulate(A, A + n, 0);
        int sum2 = accumulate(B, B + m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((sum1 - A[i] + B[j]) == (sum2 - B[j] + A[i]))
                    return 1;
            }
        }
        return -1;
    }
    int findSwapValues(int A[], int n, int B[], int m)
    {
        // Your code goes here
        int sum1 = accumulate(A, A + n, 0);
        int sum2 = accumulate(B, B + m, 0);
        sort(A, A + n);
        sort(B, B + m);
        int target = 0;
        target = (sum1 - sum2) / 2;
        if ((sum1 - sum2) % 2)
            return -1;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            int diff = A[i] - B[j];
            if (diff == target)
                return 1;
            else if (diff < target)
                i++;
            else
                j++;
        }
        return -1;
    }



};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];


        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
        cout << "\n";

    }
    return 0;
}





// } Driver Code Ends
// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];


        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
        cout << "\n";

    }
    return 0;
}





// } Driver Code Ends