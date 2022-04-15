#include<bits/stdc++.h>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
	vector <int> a;
	for(int i=0;i<queries.size();i++)
	{
		a.push_back(count(strings.begin(),strings.end(),queries[i]));
	}
	return a;
}


int main()
{
	int n;
	cin>>n;
	vector<string> strings(n);
	for(int i=0;i<n;i++)
	{
		cin>>strings[i];
	}
	int m;
	cin>>m;
	vector <string> queries(m);
	for(int i=0;i<m;i++)
	{
		cin>>queries[i];
	}
	vector <int> a=matchingStrings(strings,queries);
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
}
