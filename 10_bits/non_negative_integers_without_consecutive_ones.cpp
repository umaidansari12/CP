#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution {
public:
    int findIntegers1(int n) {
        // int cnt = 0, temp = n;
        // while (n)
        // {
        //     n /= 2;
        //     cnt++;
        // }
        // n = cnt;
        // int max = 0, base = 1;
        // for (int i = 0; i < cnt; i++)
        // {
        //     max += (base);
        //     base *= 2;
        // }
        // int a[n], b[n];
        // a[0] = b[0] = 1;
        // for (int i = 1; i < n; i++)
        // {
        //     a[i] = a[i - 1] + b[i - 1];
        //     b[i] = a[i - 1];
        // }
        // if (max == temp)
        //     return (a[n - 1] + b[n - 1]);
        // return (a[n - 1] + b[n - 1]) - (max - cnt);

        int cnt = 0;
        for (int number = 0; number <= n; number++)
        {
            int num = number;
            bool flag = false;
            vector<int> a;
            while (num > 0)
            {
                a.push_back(num % 2);
                num /= 2;
            }
            // cout << "Number :" << number << endl;
            // for (auto i : a)
            //     cout << i << " ";
            // cout << endl;
            for (int i = a.size() - 1; i >= 0; i--)
            {
                if (a[i] == 1 and a[i - 1] == 1)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
        //cout << cnt << endl;
        return n - cnt + 1;
    }

    int findIntegersBrute(int num) {
        int count = 0;
        for (int i = 0; i <= num; i++)
            if (check(i))
                count++;
        return count;
    }
    bool check(int n) {
        int i = 31;
        while (i > 0) {
            if ((n & (1 << i)) != 0 && (n & (1 << (i - 1))) != 0)
                return false;
            i--;
        }
        return true;
    }

    int findIntegersBetterBrute(int num) {
        return find(0, 0, num, false);
    }
    int find(int i, int sum, int num, boolean prev) {
        if (sum > num)
            return 0;
        if (1 << i > num)
            return 1;
        if (prev)
            return find(i + 1, sum, num, false);
        return find(i + 1, sum, num, false) + find(i + 1, sum + (1 << i), num, true);
    }

    int findIntegersBitManipulation(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    sum--;
                    break;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;
    }


};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n;
        cin >> n;
        cout << ob.findIntegers(n) << endl;
    }
    return 0;
}