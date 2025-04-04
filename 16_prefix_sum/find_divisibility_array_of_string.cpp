class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int str_len = word.size();
        vector<int> div(str_len, 0);
        long long int prev_remainder = 0, num = 0, remainder = 0;
        for (int i = 0; i < str_len; i++) {
            num = prev_remainder * 10 + (word[i] - '0');
            remainder = num % m;
            if (remainder == 0)
                div[i] = 1;
            else
                div[i] = 0;
            prev_remainder = remainder;
        }
        return div;
    }
};