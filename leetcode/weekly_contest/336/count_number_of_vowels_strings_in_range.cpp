class Solution {
public:
    bool isVowel(string str, int index) {
        if (str[index] == 'a' or str[index] == 'e' or str[index] == 'i' or str[index] == 'o' or str[index] == 'u')
            return true;
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (isVowel(words[i], 0) and isVowel(words[i], words[i].size() - 1))
                cnt++;
        }
        return cnt;
    }
};