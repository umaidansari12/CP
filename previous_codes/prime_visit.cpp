#include<bits/stdc++.h>

using namespace std;

int primevisit(int *prime,int a,int b)
{
	int count=0;
	for(int i=a;i<=b;i++)
	{
		if(prime[i]==1)
		{
			cout<<i<<" ";
			count++;
		}
	}
	cout<<endl;
	return count;
}

void primesieve(int *prime)
{
	for(int i=2;i<=100000;i+=2)
	{
		prime[i]=0;
	}
	for(int i=3;i<=100000;i+=2)
	{
		prime[i]=1;
	}
	for(int i=3;i<=1000;i+=2)
	{
		if(prime[i]==1)
		{
			for(int j=i*i;j<=100000;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	prime[2]=1;
	prime[1]=prime[0]=0;
}

int main()
{
	int prime[100000]={0};
	int t;
	primesieve(prime);
	int csum[100000]={0};
	for(int i=1;i<=100000;i++)
	{
		csum[i]=csum[i-1]+prime[i];
	}
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		//int r=primevisit(prime,a,b);
		//cout<<r<<endl;
		cout<<csum[b]-csum[a]<<endl;
	}
	return 0;
}
