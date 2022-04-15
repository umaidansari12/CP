#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*
int main(){
      int sp=2, st=1,n=5;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sp; j++) {
            printf(" ");
        }
        int val=i;
        if(i> n/2) {
            val=n+1-i;
        }
        for(int j=1; j<=st; j++) {
            printf("%d",val);
            if(j<=st/2)
                val++;
            else
                val--;

        }
        printf("\n");
        if(i<(n/2 +1)) {
            st+=2;
            sp--;
        }else {
            st-=2;
            sp++;
        }
    }
    return 0;
}
*/
int Factorial(int n)
{
    cout << "I am Calculating F("<<n<<")\n";
    if(n==0)
    {
        cout << "F("<<n<<")=1\n";
        cout << "Done !F("<<n<<")\n";
        return 1;
    }
    int F = n * Factorial(n-1);
    cout << "F("<<n<<")="<<F<<endl;
    cout << "Done !F("<<n<<")\n";
    return F;
}

int main()
{
    /*int n;
    cout << "Give me an n :";
    cin >> n;
    int res = Factorial(n);
    cout << res;
    list<int> a;
    a.push_back(5);
    a.push_front(3);
    a.push_front(4);
    a.push_back(7);
    a.push_back(8);
    for(auto i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    string s;
    cin>>s;
    long res=stoll(s,nullptr,10);
    cout<<res;
    vector <int> a;
    vector <int> b;
    a.push_back(5);
    a.push_back(3);
    a.push_back(4);
    a.push_back(7);
    a.push_back(8);
    b.push_back(5);
    b.push_back(3);
    b.push_back(4);
    b.push_back(7);
    int n=a.size();
    int m=b.size();
    for(int i=0;i<max(n,m);i++)
    {
        cout<<a[i]+b[i]<<" ";
    }
    cout<<endl;
    int sum=accumulate(a.begin(),a.end(),0);
    cout<<sum<<endl;
    reverse(a.begin(),a.end());
    for(auto i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    /*
    a.erase(a.begin());
    for(auto i : a)
    {
        cout<<i<<" ";
    }*/



    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0)
        {
            cout<<s[i];
        }
    }
    cout<<" ";
    for(int i=0;i<s.size();i++)
    {
        if(i%2!=0)
        {
            cout<<s[i];
        }
    }
}