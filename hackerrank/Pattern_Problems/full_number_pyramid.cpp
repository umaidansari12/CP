#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		for(int j=1;j<=(n-i);j++)
		{
			cout<<"  ";
		}
		for(int k=i,j=k;k<(j+i);k++)
		{
			cout<<k<<" ";
			m=k;
		}
		m--;
		for(;m>=i;m--)
		{
			cout<<m<<" ";
		}
		cout<<endl;
	}
}
