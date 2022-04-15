#include <bits/stdc++.h>

using namespace std;

int F[70];


class Solution {
public:
    long long int nthFibonacci(long long int n) {
        // code here
        if (n <= 1)
            return n;
        long long a = 1, b = 1, temp, mod = 1e9 + 7;
        for (int i = 2; i < n; i++)
        {
            temp = (a + b) % mod;
            a = b;
            b = temp;
        }
        return b;
    }
};
void Fib_iter(int n)
{
    cout << "Fibonacci Sequence upto " << n << ":\n";
    int f1 = 0, f2 = 1, f;
    cout << f1 << "\t" << f2 << "\t";
    for (int i = 2 ; i <= n; i++)
    {
        f = f1 + f2;
        cout << f << "\t";
        f1 = f2;
        f2 = f;
    }
    cout << endl;
}
int Fib_recur(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return Fib_recur(n - 1) + Fib_recur(n - 2);

}
int Fib_mem(int n)
{
    /*if(n<=1)
    {
        return n;
    }*/
    if (F[n] != -1)
    {
        return F[n];
    }
    F[n] = Fib_mem(n - 1) + Fib_mem(n - 2);
    return F[n];
}
int main()
{
    int n;
    cout << "Give me an n :";
    cin >> n;
    for (int i = 0; i < 70; i++)
    {
        F[i] = -1;
    }
    F[0] = 0, F[1] = 1;
    cout << "Fibonacci Sequence upto " << n << ":\n";
    for (int i = 0; i <= n; i++)
    {
        cout << Fib_mem(i) << "\t";
    }
    cout << endl;


}