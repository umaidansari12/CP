class Solution {
public:
    int value(char c)
    {
        if (c == 'I')
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        if (c == 'M')
            return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int n = s.size(), r = 0;
        for (int i = 0; i < n; i++)
        {
            int s1 = value(s[i]), s2;
            if (i + 1 < n)
            {
                s2 = value(s[i + 1]);
                if (s1 >= s2)
                {
                    r += s1;
                }
                else
                {
                    r = r + s2 - s1;
                    i++;
                }
            }
            else
            {
                r += s1;
            }
        }
        return r;
    }
};

class Solution {
public:
    int value(char ch) {
        if (ch == 'I')
            return 1;
        else if (ch == 'V')
            return 5;
        else if (ch == 'X')
            return 10;
        else if (ch == 'L')
            return 50;
        else if (ch == 'C')
            return 100;
        else if (ch == 'D')
            return 500;
        else if (ch == 'M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int n = s.size(), result = 0;
        for (int i = 0; i < n; i++) {
            int value1 = value(s[i]);
            if (i + 1 < n) {
                int value2 = value(s[i + 1]);
                if (value2 > value1) {
                    result = result + (value2 - value1);
                    i++;
                }
                else
                    result += value1;
            }
            else {
                result += value1;
            }
        }
        return result;
    }
};