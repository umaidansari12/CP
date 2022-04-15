#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solveBrute() {

    int n;
    long long int cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int s1 = s[i] - '0';
            int s2 = s[j] - '0';
            if ((j - i) == abs(s2 - s1))
                cnt++;
        }
    }
    cout << cnt << endl;
}

void solve() {
    int n;
    long long int cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        a[i - (s[i] - '0')]++;
        b[i + (s[i] - '0')]++;
    }
    for (auto i : a) {
        cnt += (((i.second) * (i.second - 1)) / 2);
    }
    for (auto i : b) {
        cnt += (((i.second) * (i.second - 1)) / 2);
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solveBrute();
        solve();
    }
    return 0;
}