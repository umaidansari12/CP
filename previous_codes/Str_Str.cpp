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

int strstr(string s, string x)
{
    //Your code here
    if (x.size() == 0)
        return 0;
    int n = s.size(), m = x.size(), r = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == x[0])
        {
            int j = 1;
            for (; j < m; j++)
            {
                if (s[i + j] != x[j])
                    break;
            }
            if (j == m)
            {
                r = i;
                return r;
            }
        }
    }
    return r;
}

int Solution::strStr(const string A, const string B) {
    int n = A.size(), m = B.size(), r = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == B[0])
        {
            int j = 1;
            for (; j < m; j++)
                if (A[i + j] != B[j])
                    break;
            if (j == m)
            {
                r = i;
                return r;
            }
        }
    }
    return r;
}
