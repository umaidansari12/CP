#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c,j,i,flag=0,count=0;
    cin>>r>>c;
    char a[r][c];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]=='P')
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    flag=0;
    cout<<i+1<<" "<<j+1;
    int r1=i,c1=j+1;
    while(r1<r)
    {
        while(c1<c && c1>=0)
        {
            if((r1+1)%2!=0)
            {
                if(a[r1][c1+1]=='P' || a[r1][c1+1]=='N')
                {
                    count++;
                    cout<<"VALUE OF COUNT AT"<<r1<<" "<<c1<<" "<<count<<endl; 
                    if(a[r1][c1]=='N' && a[r1+1][c1]=='P')
                    {
                        r1++;
                        count++;
                        break;
                    }                                 
                }
                c1++;
            }
            if(c1==r)
            {
                c1=r-1;
                break;
            }
            if((r1+1)%2==0)
            {
                if(a[r1][c1-1]=='P' || a[r1][c1-1]=='N')
                {
                    count++;
                    cout<<"VALUE OF COUNT AT"<<r1<<" "<<c1<<" "<<count<<endl;
                    if(a[r1][c1]=='N' && a[r1+1][c1]=='P')
                    {
                        r1++;
                        count++;
                        break;
                    }
                }
                c1--;
            }
            if(c1==-1)
            {
                c1=0;
                break;
            }
        }
        r1++;
    }
    cout<<count;
}