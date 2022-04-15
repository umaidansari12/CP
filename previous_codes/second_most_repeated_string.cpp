#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> s;
        for (int i = 0; i < n; i++)
        {
            s[arr[i]]++;
        }
        vector<pair<string, int>> r;
        for (auto i : s)
        {
            r.push_back({i.first, i.second});
        }
        sort(r.begin(), r.end(), [](const pair<string, int> lhs, const pair<string, int> rhs) {
            return lhs.second < rhs.second;
        });
        return r[r.size() - 2].first;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends