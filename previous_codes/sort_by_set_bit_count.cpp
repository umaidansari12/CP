#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:

    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr, arr + n, [](const int a, const int b)
        {
            int c = 0, n1 = a, n2 = b, d = 0;
            for (; n1; c++)
                n1 = n1 & (n1 - 1);
            for (; n2; d++)
                n2 = n2 & (n2 - 1);

            return c > d;
        });
    }
};


class Solution {
public:

    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr, arr + n, [](int x, int y) {
            return __builtin_popcount(x) > __builtin_popcount(y);
        });

        /*
        sort(arr,arr+n,[](const int a,const int b)
        {
            int c=0,n1=a,n2=b,d=0;
            while(n1)
            {
                if(n1%2)
                c++;
                n1/=2;
            }
            while(n2)
            {
                if(n2%2)
                d++;
                n2/=2;
            }
        return c>d;
        });*/
    }
};


// { Driver Code Starts.

int main()
{
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
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends