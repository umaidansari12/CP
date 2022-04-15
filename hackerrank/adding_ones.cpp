#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    vector <int> a(n);
	    for(int i=0;i<k;i++)
	    {
	        int j;
	        cin>>j;
	        for(int c=j-1;c<n;c++)
	        {
	            a[c]++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	    a.clear();
	}
	return 0;
}
