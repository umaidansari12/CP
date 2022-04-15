#include<bits/stdc++.h>

using namespace std;

int chocolateFeast(int n, int c, int m) {

    /*int sum=n/c;
    int wrappers=sum;
    while(wrappers>=m)
    {
        sum++;
        wrappers-=m;
        wrappers++;    
    }
return sum;//logic which passed all the testcases simply eating one chocolate at time increasing wrappers and decrasing it to get chocolate*/
    int sum=n/c;
    int wrappers=sum;
    while(wrappers>=m)
    {
        
        sum+=(wrappers/m);
        wrappers=wrappers/m+wrappers%m;    
    }
return sum;

}

int main()
{
    int n,c,m,t;
    cin >> t;
    while(t)
    {
    cin>>n>>c>>m;
    int res=chocolateFeast(n,c,m);
    cout<<res<<endl;
    t--;
    }
   
}