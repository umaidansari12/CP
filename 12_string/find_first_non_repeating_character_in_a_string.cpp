#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        //Your code here
        unordered_map<char, int> s;
        for (auto ch : S) {
            s[ch]++;
        }
        for (auto ch : S) {
            if (s[ch] == 1) {
                return ch;
            }
        }
        return '$';

    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--)
    {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if (ans != '$')
            cout << ans;
        else cout << "-1";

        cout << endl;

    }

    return 0;
}
// } Driver Code Ends
