#include<bits/stdc++.h>

using namespace std;

void kary(vector<int> a,int n,int k)
{
    if(n<1)
    {
        for(int i=0;i< a.size();i++)
        {
            cout << a[i];
        }
        cout<<endl;
    }
    else
    {
        for(int j=0;j<k;j++)
        {
            a[n-1]=j;
            kary(a,n-1,k);
        }
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    a.assign(n,0);
    kary(a,n,k);
}