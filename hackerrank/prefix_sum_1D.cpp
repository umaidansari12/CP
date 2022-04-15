#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,sum=0;
	cin>>n;
	vector <int> a(n);
	vector <int> prefix(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		prefix[i]=sum;
	}
	for(int i=0;i<n;i++)
	{
		cout<<prefix[i]<<" ";
	}
	cout<<endl;
}
