#include <bits/stdc++.h>

using namespace std;

vector <int> reverseArray(vector <int> a)
{
	int n=a.size();
	for(int i=0,j=n-1;i<j;i++,j--)
	{
		swap(a[i],a[j]);
	}
	return a;
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector <int> res = reverseArray(a);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
}
