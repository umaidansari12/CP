#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCharacter(string& s, string& t) {
        if (t.find(s) != string::npos)
            return 0;
        // code here
        int s_size = s.size(), t_size = t.size(), answer = INT_MAX;
        for (int i = 0; i < s_size; i++) {
            string str = "";
            for (int j = i; j < s_size; j++) {
                str += s[j];
                // cout << str << endl;
                // if (str.compare(t) == 0) {
                if (t.find(str) != string::npos) {
                    answer = min(answer, (s_size - (j - i + 1)));
                    // cout << answer << endl;
                }
            }
        }
        return answer;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob = Solution();
        cout << ob.minCharacter(s, t) << endl;
    }
}