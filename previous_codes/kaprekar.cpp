#include <bits/stdc++.h>

using namespace std;

void kaprekarNumbers(int p, int q) {
    int count=0;
    for(int i=p;i<=q;i++)
    {
        long long int s=pow(i,2);
        cout<<"Square : "<<s;
        string num=to_string(s);
        cout<<"String : "<<num;
        string n1;
        string n2;
        int si=num.size();
        cout<<"Size : "<<si;
        int d=si/2;
        cout<<"d : "<<d;
        n1=num.substr(0,d);
        if(si%2!=0)
        {
            n2=num.substr(d,d+1);
        }
        else
        {
            n2=num.substr(d,d);    
        }
        cout<<"N1 :"<<n1;
        cout<<"N2 :"<<n2;
        int n=std::stoi(n1);
        int t=std::stoi(n2);
        cout<<"N :"<<n;
        cout<<"T :"<<t;
        if((n+t)==i)
        {
            cout<<i<<" ";
            count++;
        }
    }
    if(count==0)
    {
        cout<<"INVALID RANGE";
    }
}


int main()
{
    int p,q;
    cin>>p>>q;
    kaprekarNumbers(p,q);
}