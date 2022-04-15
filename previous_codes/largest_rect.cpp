#include<bits/stdc++.h>

using namespace std;

long largestRectangle(vector<int> h) {
    vector<int> t;
    vector<long> a;
    for(int i=h.size()-1;i>=0;i--)
    {
        t.push_back(h[i]);
        int m=*min_element(t.begin(),t.end());
        a.push_back(m*t.size());
    }
    long ma=*max_element(a.begin(),a.end());
    return ma;


}

int main()
{
    int n;
    cin>>n;
    vector <int> h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    long res=largestRectangle(h);
    cout<<"Result : "<<res<<endl;
}