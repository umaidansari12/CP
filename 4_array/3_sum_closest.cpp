#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        int closest_diff = INT_MAX, ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                for (int k = j + 1; k < N; k++)
                {
                    int sum = A[i] + A[j] + A[k];
                    int diff = abs(sum - X);
                    if (diff < closest_diff)
                    {
                        closest_diff = diff;
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        int closest_diff = INT_MAX, ans = 0;
        sort(A, A + N);
        for (int i = 0; i < N; i++)
        {
            int element = A[i];
            int left = i + 1, right = N - 1;
            while (left < right)
            {
                int sum = A[left] + A[right];
                int diff = abs((sum + element) - X);
                if (diff < closest_diff)
                {
                    closest_diff = diff;
                    ans = sum + element;
                }
                if ((sum + element) == X)
                {
                    return (sum + element);
                }
                if ((sum + element) < X)
                    left++;
                else
                    right--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int X;
        cin >> X;
        Solution obj;
        cout << obj.closest3Sum(Arr, N, X) << endl;
    }
    return 0;
}  // } Driver Code Ends