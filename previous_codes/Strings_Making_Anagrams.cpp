#include <bits/stdc++.h>

using namespace std;

int makeAnagram(string a, string b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int n=a.size(),m=b.size();
    map<char,int> a1,b1;
    a1.insert(pair<char,int>('a',0));
    a1.insert(pair<char,int>('b',0));
    a1.insert(pair<char,int>('c',0));
    a1.insert(pair<char,int>('d',0));
    a1.insert(pair<char,int>('e',0));
    a1.insert(pair<char,int>('f',0));
    a1.insert(pair<char,int>('g',0));
    a1.insert(pair<char,int>('h',0));
    a1.insert(pair<char,int>('i',0));
    a1.insert(pair<char,int>('j',0));
    a1.insert(pair<char,int>('k',0));
    a1.insert(pair<char,int>('l',0));
    a1.insert(pair<char,int>('m',0));
    a1.insert(pair<char,int>('n',0));
    a1.insert(pair<char,int>('o',0));
    a1.insert(pair<char,int>('p',0));
    a1.insert(pair<char,int>('q',0));
    a1.insert(pair<char,int>('r',0));
    a1.insert(pair<char,int>('s',0));
    a1.insert(pair<char,int>('t',0));
    a1.insert(pair<char,int>('u',0));
    a1.insert(pair<char,int>('v',0));
    a1.insert(pair<char,int>('w',0));
    a1.insert(pair<char,int>('x',0));
    a1.insert(pair<char,int>('y',0));
    a1.insert(pair<char,int>('z',0));
    b1.insert(pair<char,int>('a',0));
    b1.insert(pair<char,int>('b',0));
    b1.insert(pair<char,int>('c',0));
    b1.insert(pair<char,int>('d',0));
    b1.insert(pair<char,int>('e',0));
    b1.insert(pair<char,int>('f',0));
    b1.insert(pair<char,int>('g',0));
    b1.insert(pair<char,int>('h',0));
    b1.insert(pair<char,int>('i',0));
    b1.insert(pair<char,int>('j',0));
    b1.insert(pair<char,int>('k',0));
    b1.insert(pair<char,int>('l',0));
    b1.insert(pair<char,int>('m',0));
    b1.insert(pair<char,int>('n',0));
    b1.insert(pair<char,int>('o',0));
    b1.insert(pair<char,int>('p',0));
    b1.insert(pair<char,int>('q',0));
    b1.insert(pair<char,int>('r',0));
    b1.insert(pair<char,int>('s',0));
    b1.insert(pair<char,int>('t',0));
    b1.insert(pair<char,int>('u',0));
    b1.insert(pair<char,int>('v',0));
    b1.insert(pair<char,int>('w',0));
    b1.insert(pair<char,int>('x',0));
    b1.insert(pair<char,int>('y',0));
    b1.insert(pair<char,int>('z',0));
    for(int i=0;i<n;i++)
    {
        a1[a[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        b1[b[i]]++;
    }
    int res=0;
    for(int i=97;i<=122;i++)
    {
        char c=i;
        res+=(abs(a1[c]-b1[c]));
    }
return res;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<makeAnagram(a,b)<<endl;
}
