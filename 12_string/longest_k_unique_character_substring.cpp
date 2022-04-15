//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    bool isValid(int count[], int k) {
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0)
                cnt++;
        }
        return (cnt > k);
    }
    int longestKSubstr(string s, int k) {
        // your code here
        int cnt = 0, n = s.size(), count[26] = {0};
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; i++) {
            if (count[s[i] - 'a'] == 0)
                cnt++;
            count[s[i] - 'a']++;
        }
        if (cnt < k)
            return -1;
        int curr_start = 0, curr_end = 0, max_window_size = 1, max_window_start = 0;
        memset(count, 0, sizeof(count));
        count[s[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            count[s[i] - 'a']++;
            curr_end++;
            while (isValid(count, k)) {
                count[s[curr_start] - 'a']--;
                curr_start++;
            }
            if (curr_end - curr_start + 1 > max_window_size) {
                max_window_size = curr_end - curr_start + 1;
                max_window_start = curr_start;
            }
        }
        return max_window_size;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
// } Driver Code Ends