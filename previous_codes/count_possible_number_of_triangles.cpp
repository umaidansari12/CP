#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                    if ((arr[i] + arr[j]) > arr[k] && (arr[i] + arr[k]) > arr[j] && (arr[k] + arr[j]) > arr[i])
                        count++;
            }
        }
        return count;
    }
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int count = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < n; j++)
            {
                while (k < n && arr[i] + arr[j] > arr[k])
                    k++;
                if (k > j)
                    count += (k - j - 1);
            }
        }
        return count;
    }
    int findNumberOfTriangles(int A[], int n)
    {
        // code here

        sort(A, A + n);

        int count = 0;

        for (int i = n - 1; i >= 1; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (A[l] + A[r] > A[i]) {

                    // If it is possible with a[l], a[r]
                    // and a[i] then it is also possible
                    // with a[l+1]..a[r-1], a[r] and a[i]
                    count += r - l;

                    // checking for more possible solutions
                    r--;
                }
                else

                    // if not possible check for
                    // higher values of arr[l]
                    l++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int count = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < n - 1 && arr[i] != 0; j++)
            {
                while (k < n && arr[i] + arr[j] > arr[k])
                    k++;
                count += (k - j) - 1;
            }
        }
        return count;

    }
};

int Solution::nTriang(vector<int> &A) {
    int n = A.size(), count = 0, mod = 1e9 + 7;
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 2; i++)
    {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; j++)
        {
            while (k < n && (A[i] + A[j]) > A[k])
                k++;
            count = (count + (k - j - 1) % mod) % mod;
        }
    }
    return count;
}

int Solution::nTriang(vector<int> &A) {
    // 2 pointer solution

    int ans = 0, n = A.size(), num = pow(10, 9) + 7;

    if (!n) {
        return ans;
    }

    sort(A.begin(), A.end());

    for (int k = n - 1; k >= 0; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            long int miniSum = A[i] + A[j], maxi = A[k];
            if (miniSum > maxi) {
                ans = (ans + (j - i) % num) % num;
                j--;
            }
            else {
                i++;
            }
        }
    }

    return ans;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findNumberOfTriangles(arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends