#include<bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
stack <char> a;
string n;
for(int i=0;i<s.size();i++)
{
	char c=s[i];
    if(a.empty() || a.top()!=c)
    {
    	a.push(c);
    	n.push_back(c);
	}
	else if(a.top()==c)
	{
		a.pop();
		n.pop_back();
	}
}

return (!n.empty())?n:"Empty String";
}

int main()
{
	string s;
	cin>>s;
	cout<<superReducedString(s);
}
