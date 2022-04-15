#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,sm,n,found="false";
    cin >> s;
    for(int i=2; i <= s.length(); i++)
    {
        int a=s.length()/i;
        sm=s.substr(0,a);
        for(int j=1 ; j < i;j++)
        {
            n+=sm;
        }
        if(s.compare(n)==0)
        {
            found="true";
            cout << "true";
            cout << "Value of Found :"<<found<<endl;
            break;
        }
        
    }
    if(found=="false")
    {
        cout <<"false";
    }

}