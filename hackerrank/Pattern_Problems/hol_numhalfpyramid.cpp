#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==1||j==1||j==i||i==n)
			cout<<j<<" ";
			else
			cout<<"  ";
		}
		cout<<endl;
	}
}
