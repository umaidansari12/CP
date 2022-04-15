#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int find_key(int a[],int n,int key)
{
	int s=0,e=n-1;
	while(s<=e)
	{
		int m=(s+e)/2;
		if(a[m]==key)
		{
			return m;
		}
		else if(a[s]<=a[m])
		{
			if(key<=a[m] && key>=a[s])
			{
				e=m-1;
			}
			else{
				s=m+1;
			}
		}
		else{
			if(key<=a[e] && key>=a[m])
			{
				s=m+1;
			}
			else
			{
				e=m-1;
			}
		}
	}
	return -1;
}


int main() {
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;
	cout<<find_key(a,n,key)<<endl;
	return 0;
}