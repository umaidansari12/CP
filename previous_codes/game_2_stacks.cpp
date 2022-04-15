#include<bits/stdc++.h>

using namespace std;
//My approach is not efficient i dont know why it gives TLE i'm following greedy approach choosing minimum top from 
//one of the stacks and adding it to sum and erasing the 0th index and then removing the 0th index 
int twoStacks(int x, vector<int> a, vector<int> b) {
    /*
     * Write your code here.
     */
    int sum=0;
    int count=0;
    while(sum<=x)
    {
        count++;
        if(a.size()>0 && a[0]<=b[0])
        {
            sum+=a[0];
            a.erase(a.begin());
        }
        else if(b.size()>0 && a[0]>b[0])
        {
            sum+=b[0];
            b.erase(b.begin());
        }
        
    }
    return count-1;
}

int two_stacks(int x,vector<int> a,vector<int> b)
{
    int sum=0,count=0,i=0,j=0,n=a.size(),m=b.size();
    while(i<n && sum<=x)
    {
        sum+=a[i];
        i++;
    }
    count=i;
    while(j<m && i>=0)
    {
        sum+=b[j];
        j++;
        while(sum>x && i>=0)
        {
            i--;
            sum-=a[i];
        }
        if(sum<=x && i+j>count)
        {
            count=i+j;
        }
    }
    return count;
}

int main()
{
    int x,n,m;
    cin>>n>>m>>x;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int res=two_stacks(x,a,b);
    cout<<res<<endl;
}