#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string lapin(string s)
{
    map<char,int> m1;
    int n=s.size();
    for(int i=0;i<(n/2);i++)
    {
        m1[s[i]]++;
    }
    for(int i=(n+1)/2;i<n;i++)
    {
        m1[s[i]]--;
    }
    for(auto i1=m1.begin();i1!=m1.end();i1++)
    {
        if(i1->second!=0)
        {
            return "NO";
        }
    }
    return "YES";
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<lapin(s)<<endl;
	}
	return 0;
}
