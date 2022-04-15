//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    int minxorpairBrute(int N, int arr[]) {
        //code here
        int ans = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                ans = min(ans, arr[i] ^ arr[j]);
            }
        }
        return ans;
    }
    int minxorpairNlogN(int N, int arr[]) {
        //code here
        int ans = INT_MAX;
        sort(arr, arr + N);
        for (int i = 0; i < N - 1; i++)
        {
            ans = min(ans, arr[i] ^ arr[i + 1]);
        }
        return ans;
    }
    //O(N) can be achieve using Trie
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends