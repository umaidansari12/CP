#include <bits/stdc++.h>

using namespace std;

void maxSubarray(vector<int> arr) {
    vector <int> s;
    int n=arr.size();
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            int sum=0;
            for(int k=j;k<j+i;k++)
            {
                sum+=arr[k];
            }
            s.push_back(sum);
        }
    }
    for(int i:s)
    {
        cout<<i<<" ";
    }
}

int main()
{
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    /*int res=*/maxSubarray(a);
    //cout<<res;
}