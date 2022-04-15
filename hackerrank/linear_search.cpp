#include<bits/stdc++.h>

using namespace std;

int linear_search(vector<int> a,int n,int k)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector <int> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<linear_search(a,n,k)<<endl;
	}
}
