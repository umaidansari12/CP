#include <bits/stdc++.h>
int findGcd(int x, int y)
{
    // Write your code here
    // O(log(min(a,b)))
    /*    while (x > 0 and y > 0) {
            if (x > y)
                x = x % y;
            else
                y = y % x;
        }
        if (x == 0)
            return y;
        return x;*/


    // Write your code here
    //O(min(a,b))
    int gcd = 1;
    for (int i = 1; i <= min(x, y); i++) {
        if (x % i == 0 and y % i == 0) {
            gcd = i;
        }
    }
    return gcd;



}

int gcd(int a, int b)
{
    //Write your code here
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


/*
euclidean algorithm

gcd(a,b) = gcd(a-b,b) a>b
gcd(a,b) = gcd(a%b,b) a>b

greater % smaller -> 0 if one is 0 other one is gcd

TC -> O(logphi(min(a,b)))

*/