//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    //Function to arrange all letters of a string in lexicographical
    //order using Counting Sort.
    string countSort(string arr) {
        // code here
        int cnt[26] = {0};
        for (auto i : arr)
            cnt[i - 'a']++;
        string s;
        for (int i = 0; i < 26; i++)
        {
            s += (string(cnt[i], i + 'a'));
        }
        return s;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        Solution obj;
        cout << obj.countSort(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends