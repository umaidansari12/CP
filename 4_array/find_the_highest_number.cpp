#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findPeakElement(vector<int>& a)
    {
        // Code here. first approach is to use linear  search and find the
        // maximum number out of it. This will take O(n) time while
        // traversing the array.
        int _max = a[0];
        for (int i = 0; i < a.size(); i++) {
            _max = max(a[i], _max);
        }
        return _max;
    }
    int findPeakElement(vector<int>& arr)
    {
        // Code here.
        //second approach is to use binary search on the given array as it is following the order of increasing then decreasing

        int n = arr.size();
        int low = 0 , high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // if there are only two elements left in the partition and first element is greater than the second element then return the first element
            if ((high == low + 1) and arr[low] >= arr[high])
                return arr[low];
            // if there are only two elements left in the partition and first element is less than the second element then return the second element
            if ((high == low + 1) and arr[low] < arr[high])
                return arr[high];
            // if the adjacent elements are lesser than the current element then return the current element
            if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
                return arr[mid];
            // if the current element is less than the next element then the element lies on the right side move the low pointer
            else if ((mid + 1) < n and arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            // if the current element is greater than the next element then the element lies on the left side move the right pointer
            else {
                high = mid - 1;
            }
        }

        return 0;
    }
};



// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        int ans = ob.findPeakElement(a);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends