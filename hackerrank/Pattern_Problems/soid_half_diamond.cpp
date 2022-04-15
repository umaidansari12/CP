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
		cout<<endl;
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int k=i;k>=1;k--)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
}
