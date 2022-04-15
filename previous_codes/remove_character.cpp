// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
public:
    string removeChars(string string1, string string2) {
        // code here
        unordered_map<char, int> m;
        for (int i = 0; i < string2.size(); i++)
        {
            m[string2[i]]++;
        }
        string s;
        for (int i = 0; i < string1.size(); i++)
        {
            if (m.find(string1[i]) == m.end())
                s += string1[i];
        }
        return s;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1, string2;
        cin >> string1;
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1, string2) << endl;
    }
    return 0;
}
// } Driver Code Ends