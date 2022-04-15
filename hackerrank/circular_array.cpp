#include<bits/stdc++.h>

using namespace std;

void print(char *a,int n,int index)
{
	for(int i=index;i<n+index;i++)
	{
		cout<<a[i%n]<<" ";
	}
	cout<<endl;
}

void print1(char *a,int n,int index)
{
	char b[2*n+2];
	for(int i=0;i<n;i++)
	{
		b[i]=b[n+i]=a[i];
	}
	b[2*n+1]='\0';
	for(int i=index;i<n+index;i++)
	{
		cout<<b[i]<<" ";
	}
}

int main()
{
	int n,index;
	cin>>n>>index;
	char *a;
	cin.get();
	cin.getline(a,20);
	for(int i=0;a[i]!='\0';i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	print1(a,n,index);
}
