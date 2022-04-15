#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << __builtin_popcount(n) << endl;
    //Try to convert the N into binary representation and count the 1's.
    int ans = 0, t = n, l = 1;
    while (n > 0)
    {
        ans += (n & 1);
        n = n >> 1;
    }
    cout << ans << endl;
    ans = 0;
    while (l > 0)
    {
        ans += (t & l);
        l = l << 1;
    }
    cout << ans << endl;
    return 0;
}

class Solution
{
public:
    int setBits(int N)
    {
        int  count = 0;
        while (N)
        {
            N &= (N - 1) ;
            count++;
        }
        return count;
    }
};
