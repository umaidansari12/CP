#include<bits/stdc++.h>

using namespace std;

long strangeCounter(long t) {
    long v=3;
    long iv=v;
    for(long i=2;i<=t;i++)
    {
        if(v!=1)
        {
            v=v-1;
        }
        else if(v==1)
        {
            iv=2*iv;
            v=iv;
        }
        if(i==t)
        {
            break;
        }
        

    }

long strange_counter(long t)
{
    long rem=3
    while(t>rem)
    {
        t-=rem;
        rem*=2;
    }
    return rem-t+1;
}
        
return v;
}

int main()
{
    long t;
    cin>>t;
    long r=strangeCounter(t);
    cout<<"RESULT :"<<r<<endl;
}