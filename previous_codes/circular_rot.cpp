#include<bits/stdc++.h>

using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> b;
    vector<int> c;
    k=k%a.size();
    for(int i=a.size()-k;i<a.size();i++)
    {
        b.push_back(a[i]);
    }
    for(int i=0;i<a.size()-k;i++)
    {
        b.push_back(a[i]);
    }
    for(int i=0;i<queries.size();i++)
    {
        c.push_back(b[queries[i]]);
    }
    return c;
}


int main()
{
    vector<int> a;
    int n,k,q,x;
    vector<int> qu;
    cin >> n>> k >> q;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<q;i++)
    {
        cin >> x;
        qu.push_back(x);
    }
    vector <int> res=circularArrayRotation(a,k,qu);
    cout<<"RESULT :"<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}