#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int a[], int n, int s1, int s2, int len1, int len2)
{
    if (n < 0)
    {
        if (abs(len1 - len2) > 1)
            return INT_MAX;
        return abs(s1 - s2);
    }
    return min(solve(a, n - 1, s1, s2, len1, len2), solve(a, n - 1, s1 + a[n], s2 - a[n], len1 + 1, len2 - 1));
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int s1 = 0;
        int s2 = sum;
        int mi = solve(a, n - 1, s1, s2, 0, n);
        int ans1 = (float(sum) / 2.0 - float(mi) / 2.0);
        int ans2 = (float(sum) / 2.0 + float(mi) / 2.0);
        cout << ans1 << " " << ans2 << endl;
    }


    return 0;
}