#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int pickingNumbers(vector<int> a) {
    vector <int> b(100);
    for(int i=0;i<a.size();i++)
    {
        b[a[i]]++;
    }
    int m=0;
    for(int i=0;i<a.size();i++)
    {
        m=max(m,b[i]+b[i+1]);
    }
return m;
}



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
   }
    int res=pickingNumbers(a);
    cout<<res;
    return 0;
}