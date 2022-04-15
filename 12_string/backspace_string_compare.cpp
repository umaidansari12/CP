class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", t1 = "";
        for (auto i : s)
        {
            if (i == '#')
            {
                if (!s1.empty())
                    s1.pop_back();
            }
            else
                s1 += i;
        }
        for (auto i : t)
        {
            if (i == '#')
            {
                if (!t1.empty())
                    t1.pop_back();
            }
            else
                t1 += i;
        }
        return s1 == t1;
    }
};