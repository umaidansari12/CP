#include <bits/stdc++.h>

using namespace std;

int expo(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    return x * expo(x,n-1);
}

int pow(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        int y=pow(x,n/2);
        return y*y;
    }
    return x * expo(x,n-1);
}

int mod_expo(int x,int n,int m)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        int y = mod_expo(x,n/2,m);
        return ((y%m)*(y%m))%m;
    }
    return ((x%m)*(mod_expo(x,n-1,m)%m))%m;
}
int main()
{
    int x,n,m;
    cout << "Enter X :";
    cin >> x ;
    cout << "Enter N :";
    cin >> n;
    cout << "Enter M :";
    cin >> m;
    int res=mod_expo(x,n,m);
    cout << res;
}
