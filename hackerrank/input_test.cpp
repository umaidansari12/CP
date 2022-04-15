#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n,k,count=0,x;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x%k==0)
		count++;
	}
	cout<<count<<endl;
}
