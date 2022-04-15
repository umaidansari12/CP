#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        // your code here
        int diff = INT_MAX, ans = 0;
        //we are taking every pair of elements and making their sum closest to zero
        //by taking absolute sum and making it near to zero
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (diff > abs(arr[i] + arr[j]))
                {
                    diff = abs(arr[i] + arr[j]);
                    ans = arr[i] + arr[j];
                }
            }
        }
        return ans;
    }
    int closestToZero(int arr[], int n)
    {
        // your code here
        //we use the property of sorted  array and we know that the array is already sorted
        //so we take two pointers and place one on the beginiing and other pointer on the another end of the array
        //now we reduce the sum according if the sum is 0 then we return it else if we got the sum which is already less than the min_sum
        // the we change our min_sum to the current sum and if we got the sum same as absolute of min_sum then we take maximum sum
        // if sum is -ve we increase the difference
        // else if sum is +ve we decrease the difference
        sort(arr, arr + n);
        int min_sum = INT_MAX, low = 0, high = n - 1;
        while (low < high)
        {
            int sum = (arr[low] + arr[high]);
            if (sum == 0)
                return 0;
            if (abs(sum) < abs(min_sum))
            {
                min_sum = sum;
            }
            if (abs(sum) == abs(min_sum))
            {
                min_sum = max(min_sum, sum);
            }
            if (sum < 0)
                low++;
            else
                high--;
        }
        return min_sum;
    }
};

// { Driver Code Starts.
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends