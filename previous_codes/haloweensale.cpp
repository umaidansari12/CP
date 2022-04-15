#include <bits/stdc++.h>

using namespace std;

int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int sum=p,count=1;
    while(sum+p<s)
    {
        if(p<=m)
        {
            p=m;
        }
        else
        {
            p=p-d;
        }
       
        sum=sum+p;
        count++;
    }
return count;
}
int howmanygames(int p, int d, int m, int s)
{
    int count=0;
    while(s>=p)
    {
        s-=p;
        p-=d;
        if(p<m)
        {
            p=m;
        }
        count++;
    }
    return count;

}

int main()
{
    int p,d,m,s;
    cin>>p>>d>>m>>s;
    int res=howManyGames(p,d,m,s);
    cout << res;
}