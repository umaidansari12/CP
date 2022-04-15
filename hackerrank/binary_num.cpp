#include<bits/stdc++.h>

using namespace std;

int bin_count(int n)
{
	int count=0,max=0;
	while(n)
	{
		if(n&1)
		{
			count++;
		}
		else
		{
			count=0;
		}
		if(max<count)
		{
			max=count;
		}
		n>>=1;
	}
	return max;
}
int main()
{
	int n,count=0,max=0;
	cin>>n;
	int temp=n;
	while(n>0)
	{
		if(n%2==0)
		{
			count=0;
		}
		else
		{
			count++;
		}
		if(max<count)
		{
		max=count;
		}
		n=n/2;
	}

	cout<<max<<endl;
	cout<<bin_count(temp);
}


