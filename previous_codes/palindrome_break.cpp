class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1)
            return "";
        string res1 = palindrome, res2 = palindrome;
        vector<string> r;
        for (int i = 0; i < (n / 2); i++)
        {
            if (palindrome[i] == palindrome[n - i - 1])
            {
                char ch = palindrome[i];
                if (ch == 'a')
                {
                    res1[i] = 'b';
                    res2[n - i - 1] = 'b';
                }
                else
                {
                    res1[i] = 'a';
                    res2[n - i - 1] = 'a';
                }
                r.push_back(res1);
                r.push_back(res2);
                res1[i] = ch;
                res2[n - i - 1] = ch;
            }
        }
        sort(r.begin(), r.end());
        return r[0];

    }
};

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1)
            return "";
        for (int i = 0; i < (n / 2); i++)
        {
            if (palindrome[i] > 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;

    }
};