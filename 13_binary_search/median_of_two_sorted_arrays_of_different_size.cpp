//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        // Edge case is there if the array is larger and we took out some
        if (array1.size() > array2.size())
            return MedianOfArrays(array2, array1);
        int n = array1.size(), m = array2.size(), low = 0, high = n;
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = ((n + m + 1) / 2) - cut1;

            int left1 = cut1 == 0 ? INT_MIN : array1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : array2[cut2 - 1];

            int right1 = cut1 == n ? INT_MAX : array1[cut1];
            int right2 = cut2 == m ? INT_MAX : array2[cut2];

            if (left1 <= right2 and left2 <= right1) {
                if ((n + m) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else {
                    return double(max(left1, left2));
                }
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }

        }
        return 0.0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i) {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}


// } Driver Code Ends