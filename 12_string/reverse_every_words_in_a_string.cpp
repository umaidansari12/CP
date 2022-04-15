#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        string token;
        stringstream ss(S);
        vector<string> tokens;
        while (getline(ss, token, '.'))
        {
            tokens.push_back(token);
        }
        string res;
        for (int i = tokens.size() - 1; i >= 0; i--)
        {
            res += tokens[i] + ".";
        }
        return res.substr(0, res.size() - 1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}  // } Driver Code Ends