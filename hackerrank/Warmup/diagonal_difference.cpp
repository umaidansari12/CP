#include<bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> ar)
{
	int d1=0,d2=0;
	for(int i=0;i<ar[0].size();i++)
	{
		d1+=ar[i][i];
	}
	for(int i=0,j=ar[0].size()-1;i<ar[0].size(),j>=0;i++,j--)
	{
		d2+=ar[i][j];
	}
	return abs(d1-d2);
}

int diagonaldifference(vector<vector<int>> arr)
{
	int d1=0,d2=0,n=arr[0].size();
	for(int i=0;i<arr[0].size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
		{
			if(i==j)
			{
				d1+=arr[i][j];
			}
			if(i==n-j-1)
			{
				d2+=arr[i][j];
			}
		}
	}
	return abs(d1-d2);
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> arr(n,vector <int> (n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<diagonaldifference(arr)<<endl;
}
