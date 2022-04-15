#include<bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(vector <int> arr)
{
	return count(arr.begin(),arr.end(),*max_element(arr.begin(),arr.end()));
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
	cout<<birthdayCakeCandles(arr);
}
