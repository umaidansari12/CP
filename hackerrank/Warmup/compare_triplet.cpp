#include <bits/stdc++.h>

using namespace std;

vector <int> compareTriplets(vector <int> a,vector<int> b)
{
	vector<int> res(2);
	for(int i=0;i<3;i++)
	{
		if(a[i]<b[i])
		{
			res[1]++;
		}
		else if(a[i]>b[i])
		{
			res[0]++;
		}
	}
	return res;
}

int main()
{
	vector <int> a(3),b(3);
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<3;i++)
	{
		cin>>b[i];
	}
	vector <int> res=compareTriplets(a,b);
	for(int i=0;i<2;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
