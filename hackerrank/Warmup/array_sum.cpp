#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(vector<int> arr)
{
	return accumulate(arr.begin(),arr.end(),0);
}

int main()
{
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<simpleArraySum(arr);
}
