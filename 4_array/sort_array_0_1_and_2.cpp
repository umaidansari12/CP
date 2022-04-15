#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
public:
    // Counting Sort
    void sort012Brute(int a[], int n)
    {
        // coode here
        int count[3] = {0};
        for (int i = 0; i < n; i++)
        {
            count[a[i]]++;
        }
        for (int i = 0, k = 0; i < 3; i++)
        {
            for (int j = 0; j < count[i]; j++)
                a[k++] = i;
        }

    }
    void sort012(int a[], int n)
    {
        // coode here
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
                swap(a[mid++], a[low++]);
            else if (a[mid] == 2)
                swap(a[mid], a[high--]);
            else
                mid++;
        }
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++) {
            cout << a[i]  << " ";
        }

        cout << endl;


    }
    return 0;
}

// } Driver Code Ends