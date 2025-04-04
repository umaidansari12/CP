#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int _size = s.size(), ans = 0, changes = 0, most_frequent = 0;
        for (int i = 0; i < _size; i++) {
            int hash_map[26] = {0};
            for (int j = i; j < _size; j++) {
                hash_map[s[j] - 'A']++;
                most_frequent = max(most_frequent, hash_map[s[j] - 'A']);
                changes = (j - i + 1) - most_frequent;
                if (changes <= k) {
                    ans = max(ans, j - i + 1);
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int helper(string s, int _size, int k) {
        unordered_map<int, int> m;
        int most_frequent = 0;
        for (int i = 0; i < _size; i++) {
            m[s[i]]++;
            most_frequent = max(most_frequent, m[s[i]]);
        }
        // cout << s << "-" << _size << "-" << most_frequent << endl;

        // if (most_frequent != _size) {
        //     if (most_frequent + k > _size)
        //         return _size;
        //     return most_frequent + k;
        // }
        // return most_frequent;


        if (_size - most_frequent  <= k)
            return _size;
        return 0;
    }
    int characterReplacement(string s, int k) {
        int _size = s.size(), ans = 0;
        for (int i = 0; i < _size; i++) {
            string temp = "";
            for (int j = i; j < _size; j++) {
                temp += s[j];
                ans = max(ans, helper(temp, j - i + 1, k));
                // cout << ans << endl;
            }
        }
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob = Solution();
        cout << ob.characterReplacement(s, k) << endl;
        // cout << "--------------------------------------" << endl;
    }
}
