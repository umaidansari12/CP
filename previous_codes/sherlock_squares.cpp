#include <bits/stdc++.h>

using namespace std;

int squares(int a, int b) {
    int count=0;
    for(int i=a;i<=b;i++)
    {
        double res=sqrt(i);
        int d=(int)res;
        if(res-d==0)
        {
            count++;
        }
    }
return count;

}

int main()
{
    /*int a,b,res,t;
    cin>>t;
    while(t--)
    {
        cin >>a>>b;
        res=squares(a,b);
        cout<<res<<endl;
    }*/
    int t;
    cin>>t;
    double res=sqrt(t);
    cout<<res;
    

}