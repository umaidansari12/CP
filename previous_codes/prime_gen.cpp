#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	if(n==1)
		return false;
	if(n==2)
		return true;
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
bool isprime(int n)
{
	if(n==1)
		return false;
	if(n==2)
		return true;
	for(int i=2;i*i<n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

/*int main() {
	int a,b,i,j,t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int count=0;
	for(i=a;i<=b;i++)
	{
		int n=sqrt(i);
        if(i!=1)
        {
            for(j=2;j<=n;j++)
            {
                if(i%j==0)
                {
                    break;
                }
            }
        }
		if(j==n+1)
		{
			count++;
		}
	}
	cout<<endl<<count<<endl;
	}

	return 0;
}*/

int main() {
	
	// your code here
	int t,m,n,flag;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> m >>n;
		for(int j=m ; j <=n ; j++)
		{
			flag=0;
			for(int k=2; k <= sqrt(j) ; k++)
			{
				if(j%k==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0 && j!=1)
			{
				cout << j <<endl;
			}
		}
	}

	return 0;
}