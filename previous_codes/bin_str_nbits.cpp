#include <bits/stdc++.h>

using namespace std;

void binary(vector<int> a,int n)
{
    if(n < 1)
    {
        for(int i : a)
        {
            cout<< i;
        }
        cout<<endl;
    }
    else
    {
        a[n-1]=0;
        binary(a,n-1);
        a[n-1]=1;
        binary(a,n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    a.assign(n,0);
    binary(a,n);

}