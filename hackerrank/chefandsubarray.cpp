#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int subarray(vector<int> a,int n,int k)
{
    int count=0;
	for(int i=0;i<n;i++)
	{
	    int bit=0;
	    for(int j=i;j>=0;j--)
	    {
	        bit +=(bit|a[j]);
	    }
	    if(bit>=k)
	    {
	        count++;
	    }
	}
	
    return n-count+1;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector <int> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<subarray(a,n,k)<<endl;
	}
	return 0;
}

