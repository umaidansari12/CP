#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long int findlcm(int arr[], int n)
{

    long long int ans = arr[0];

    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));

    return ans;
}

int main()
{
    int arr[3];
    int t,days;
    cin >> t;
    for(int b=0;b < t;b++)
    {
        cin >> days;
        days *=24;
        for(int i =0 ; i < 3;i++)
        {
            cin >> arr[i];
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        long long int a = findlcm(arr, n);
        int ans = days / a;
        cout << ans << endl;

    }
}
