#include<bits/stdc++.h>

using namespace std;

void miniMaxSum(vector <int> arr)
{
	long a=0;
  	long long int sum=accumulate(arr.begin(),arr.end(),a);
    int max=*max_element(arr.begin(),arr.end());
    int min=*min_element(arr.begin(),arr.end());
    cout<<sum-max<<" "<<sum-min;
}

int main()
{
	vector<int> arr(5);
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	miniMaxSum(arr);
}


