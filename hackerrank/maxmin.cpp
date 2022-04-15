#include <bits/stdc++.h>

using namespace std;

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(),arr.end());
    cout<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<arr[k-1]<<" "<<arr[0]<<endl;
    return arr[k-1]-arr[0];
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxMin(k,arr);
}
