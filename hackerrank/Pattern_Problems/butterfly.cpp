#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=i;k++)
		{
			cout<<"* ";
		}
		for(int k=2*(n-i);k>0;k--)
		{
			cout<<"  ";
		}
		for(int k=1;k<=i;k++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	for(int i=n;i>=1;i--)
	{
		for(int k=i;k>=1;k--)
		{
			cout<<"* ";
		}
		for(int k=2*(n-i);k>0;k--)
		{
			cout<<"  ";
		}
		
		for(int k=i;k>=1;k--)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
}
