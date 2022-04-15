#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    /*  Function to check if two strings are anagram
    *   a, b: input string
    */
    bool isAnagram(string a, string b) {

        // Your code here
        if (a.size() != b.size())
            return false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                return false;
        return true;

    }
    bool isAnagramOptimal(string a, string b) {

        // Your code here.
        map<int, int> m;
        for (int i = 0; i < a.size(); i++)
            m[a[i]]++;
        for (int i = 0; i < b.size(); i++)
        {
            m[b[i]]--;
            if (m[b[i]] < 0)
                return false;
        }
        return true;

    }
    bool isAnagram(string a, string b) {

        // Your code here.
        if (a.size() != b.size())
            return false;
        map<int, int> m1, m2;
        for (int i = 0; i < a.size(); i++)
            m1[a[i]]++;
        for (int i = 0; i < b.size(); i++)
        {
            m2[b[i]]++;
        }
        for (auto i : m1)
        {
            if (m1[i.first] != m2[i.first])
                return false;
        }
        return true;

    }
};

// { Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
// } Driver Code Ends