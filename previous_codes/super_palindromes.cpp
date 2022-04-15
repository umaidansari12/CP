#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int superpalindromesInRange(string left, string right) {

        long l = stol(left);
        long r = stol(right);
        int count = 0;
        cout << l << " " << r << endl;


        for (int j = 1; j <= 100000; j++)
        {
            string n = to_string(j);
            string s = n;
            for (int i = n.size() - 1; i >= 0; i--)
            {
                s += n[i];
            }
            long n1 = stol(s);
            cout << s << endl;
            n1 *= n1;
            if (n1 > r)
                break;
            else if (n1 >= l && isPalindrome(n1))
                count++;
        }
        for (int j = 1; j <= 100000; j++)
        {
            string n = to_string(j);
            string s = n;
            for (int i = n.size() - 2; i >= 0; i--)
            {
                s += n[i];
            }
            long n1 = stol(s);
            cout << s << endl;
            n1 *= n1;
            if (n1 > r)
                break;
            else if (n1 >= l && isPalindrome(n1))
                count++;
        }
        return count;

    }

    bool isPalindrome(long n)
    {
        return n == reverse(n);
    }

    bool reverse(long n)
    {
        long rev = 0;
        while (n > 0)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string l, r;
        cin >> l;
        cin.ignore();
        cin >> r;
        Solution obj;
        cout << obj.superpalindromesInRange(l, r) << endl;
    }
}