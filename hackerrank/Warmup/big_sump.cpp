#include<bits/stdc++.h>

using namespace std;

long aVeryBigSum(vector <long> ar)
{
	long long int a=0;
	return accumulate(ar.begin(),ar.end(),a);
}

int main()
{
	int n;
	cin>>n;
	vector <long> ar(n);
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	long long int ans=aVeryBigSum(ar);
	cout<<ans<<endl;
}
