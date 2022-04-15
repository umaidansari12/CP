#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector <int> a, int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int item;
    cin>>item;
    sort(a.begin(),a.end());
    auto loc=upper_bound(a.begin(),a.end(),item);
    cout<<*loc;
    int res=binarySearch(a,*loc,0,a.size());
    cout<<"Position : "<<res;
    
    return 0;
}