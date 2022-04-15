#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=1000,sum=0;
    for(int i=0;i<n;i++)
    {
        if(i%3==0 || i%5==0)
        {
            cout<<i<<" ";
            sum+=i;
        }
    }
    cout<<endl<<sum<<endl;
}