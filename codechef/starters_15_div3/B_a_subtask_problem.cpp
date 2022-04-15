#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, k, countOne = 0, count = 0;
        cin >> n >> m >> k;
        int a[n] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                countOne++;
            if (a[i] == 1 and i < m)
                count++;
        }
        if (countOne == n)
            cout << 100 << endl;
        else if (count == m)
            cout << k << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}