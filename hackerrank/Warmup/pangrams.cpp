#include <bits/stdc++.h>

using namespace std;

string pangrams(string s) {
	vector <int> l(26,0);
	for(int i=0;i<s.size();i++)
	{
		char c=s[i];
		if(c>=97 && c<=122)
		{
			l[c-'a']++;
		}
		else if(c>=65 && c<=90)
		{
			l[c-'A']++;
		}
	}
	for(int i=0;i<l.size();i++)
	{
		if(l[i]==0)
		{
			return "not pangram";
		}
	}	
	return "pangram";
}

int main()
{
	string s;
	getline(cin,s);
	cout<<pangrams(s)<<endl;
}
