#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Write your printDivisors function here

void printDivisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}

void printDivisors(int n) {

    /*n = 36
    if i is the divisor then i is dividing n completely with a quotient, so that means n/i will also be a divisors
    1 36
    2 18
    3 12
    4 9
    6 6
    9 4
    12 3
    18 2
    36 1*/

    vector<int> divisors;
    // O(sqrt(n))
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if ((n / i) != i) {
                divisors.push_back(n / i);
            }
        }
    }

    // O ( no of factors * log(no of factors))
    sort(divisors.begin(), divisors.end());
    // O (no of factors)
    for (int i = 0; i < divisors.size(); i++) {
        cout << divisors[i] << " ";
    }
}


int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}
