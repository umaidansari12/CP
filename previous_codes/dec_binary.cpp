#include <bits/stdc++.h>

using namespace std;

#define INT_BITS sizeof(int)*8

void toBinary(int N)
{
    int bit[32];
    int i = 0;
    while (N > 0)
    {
        bit[i] = N % 2;
        N /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bit[j]);
}

long long int binary_to_dec(vector<int> a)
{
    long long int num = 0;
    for (int i = a.size() - 1; i >= 0; i++)
    {

        num = num + a[i] * pow(2, i);
    }
    return num;
}


int rightRotate(int n, unsigned int d)
{
    /* In n>>d, first d bits are 0.
    To put last 3 bits of at
    first, do bitwise or of n>>d
    with n <<(INT_BITS - d) */
    return (n >> d) | (n << (INT_BITS - d));
}

int main()
{
    int n;
    cin >> n;
    /*int b=(int)bitset<3>(rightRotate(n,1));

    cout<<b;*/
    vector<int>b;
    while (n > 0)
    {
        int a = n % 2;
        b.push_back(a);
        n = n / 2;
    }
    for (auto i : b)
    {
        cout << i;
    }
    cout << endl;
    long long int nu = binary_to_dec(b);
    cout << nu;
}