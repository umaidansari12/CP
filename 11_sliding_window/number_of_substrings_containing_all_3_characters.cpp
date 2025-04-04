class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), count_a = 0, count_b = 0, count_c = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int count_a = 0, count_b = 0, count_c = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a') {
                    count_a++;
                }
                if (s[j] == 'b') {
                    count_b++;
                }
                if (s[j] == 'c') {
                    count_c++;
                }
                if (count_a >= 1 and count_b >= 1 and count_c >= 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0;
        int last_seen[3] = { -1, -1, -1};
        for (int right = 0; right < n; right++) {
            last_seen[s[right] - 'a'] = right;

            if (last_seen[0] != -1 and last_seen[1] != -1 and last_seen[2] != -1) {
                ans += (1 + min(last_seen[0], min(last_seen[1], last_seen[2])));
            }
        }
        return ans;
    }
};