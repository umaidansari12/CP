#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    int n=arr.size(),count=0,i=0,j=1,k=2;
    while(i<(n-2))
    {
        while(j<(n-1))
        {
            j=i+1;
            while(k<n)
            {
                k=j+1;
                if(arr[j]-arr[i]==d && arr[k]-arr[j]==d)
                {
                    count++;
                }
                k++;
            }
            j++;
        }
        i++;
    }

return count;
}

int main(){
    int n,d;
    cin>>n>>d;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int res=beautifulTriplets(d,a);
    cout<<res;


    return 0;
}