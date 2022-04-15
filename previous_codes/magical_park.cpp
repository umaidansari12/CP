#include <bits/stdc++.h>

using namespace std;

void magical_park(char c[][100],int n,int m,int s,int k)
{
    bool success=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s<k)
            {
                success=false;
                break;
            }
            if(c[i][j]=='.')
            {
                s-=2;          
            }
            else if(c[i][j]=='*')
            {
               s+=5;
            }
            else
            {
                break;
            }
            if(j!=m-1)
            {
                s--;
            }
          
        }
    }
    if(success)
    {
        cout<<"Yes\n"<<s;
    }
    else
    {
        cout<<"No";
    }
    
}

int main()
{
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    char a[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    magical_park(a,n,m,s,k);
}