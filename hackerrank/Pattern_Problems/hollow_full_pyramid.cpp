#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			cout<<" ";
		}
		for(int k=0;k<=i;k++)
		{
			if(k==0||i==0||k==i||i==n-1)
			cout<<"* ";
			else
			cout<<"  ";
		}
		cout<<endl;
	}
}
