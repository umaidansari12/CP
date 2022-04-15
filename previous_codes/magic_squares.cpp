#include<bits/stdc++.h>

using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    vector <int> r_sm;
    int n=s[0].size();
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=s[i][j];
        }
        r_sm.push_back(sum);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=s[i][i];
    }
    r_sm.push_back(sum);
    sum=0;
    int i,j;
    for(i=n-1,j=0;i>=0,j<n;i--,j++)
    {
        sum+=s[j][i];
    }
    r_sm.push_back(sum);
    cout<<"ROW SUM : "<<endl;
    for(int i:r_sm)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    sum=0;
    int max=*max_element(r_sm.begin(),r_sm.end());
    cout<<"MAX FROM ROW SUM : "<<max<<endl;
    for(int i=0;i<n;i++)
    {
        int m=*max_element(s[i].begin(),s[i].end());
        cout<<"MAX of "<<i<<" row : "<<m<<endl;
        sum+=(max-r_sm[i]);
    }

return sum;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    int x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x;
            a[i].push_back(x);
        }
    }
    int res=formingMagicSquare(a);
    cout<<res;
}