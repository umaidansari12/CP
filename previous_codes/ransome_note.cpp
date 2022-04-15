#include <bits/stdc++.h>

using namespace std;

int canConstruct(string a,string b)
{
    int a1=a.length(),b1=b.length();
    int flag=0;
    for(int i=0,j=0; i !=a.length() || j!=b.length() ;i++,j++)
    {
        if(a[i]==b[i])
        {
            flag++;
            continue;
        }
    }
    return flag;
}

int main()
{
    string a,b;
    cin>>a>>b;
    if(canConstruct(a,b)==a.length()-1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}