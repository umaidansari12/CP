#include <bits/stdc++.h>
int countDigit(long long x) {
    // Write your code here.
    int cnt = 0;
    while (x > 0) {
        cnt++;
        x = x / 10;
    }
    return cnt;
}