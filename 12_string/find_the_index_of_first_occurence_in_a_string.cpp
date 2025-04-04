class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size(), r = -1;
        if (m == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (haystack[i] == needle[0])
            {
                int j = 1;
                for (j = 1; j < m; j++)
                {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == m) {
                    r = i;
                    return r;
                }
            }
        }
        return r;
    }
};