//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    vector<int> farNumber(int n, vector<int> a) {
        //code here()
        vector<int> r;
        int suffix_min[n];
        suffix_min[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(suffix_min[i + 1], a[i]);
        }
        for (int i = 0; i < n; i++) {
            int low = i + 1, high = n - 1, ans = -1;

            while (low <= high) {
                int mid = (low + high) / 2;

                // If currnet element in the suffix_min
                // is less than a[i] then move right
                if (suffix_min[mid] < a[i]) {
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            r.push_back(ans);
        }
        return r;
    }

};

// { Driver Code Starts.
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution obj;
        vector<int> answer = obj.farNumber(N, Arr);
        for (auto i : answer)
            cout << i << " ";
        cout << endl;
    }
}  // } Driver Code Ends