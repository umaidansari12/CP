#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int binomaialCoeff(int n,int k)
{
	int res=1;
	if(k>n-k)
	k=n-k;
	for(int i =0;i< k;i++)
	{
		res*=(n-1);
		res/=(i+1);
	}
	return res;
}

int main() {
	vector<int> a;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			cout << " ";
		}
		for(int l=0;l<=i;l++)
		{
			cout<<binomaialCoeff(i,l)<<" ";
		}
		cout<<endl;
	}
	return 0;
}