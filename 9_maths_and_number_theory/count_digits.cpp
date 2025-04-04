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

#include <bits/stdc++.h>
int countDigit(long long x) {
    // Write your code here.
    int cnt = (int)log10(x) + 1;
    return cnt;
}

// extraction of digits time complexity
// O(log10(n)) -> no. of times the loop running is same as log10(n)
// whenever division happens and if it is by 10 you say log10(n) if by 2 log2(n) if by 5 log5(n) -> logarithmic complexity trick in division , no of iterations depends on division