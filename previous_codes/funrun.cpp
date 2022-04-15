#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t,x,i,max1,max2;
	vector<int>a;
	vector<int>b;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(i=0;i < n;i++)
	    {
	        cin >> x;
	        a.push_back(x);
	    }
	    for(i=0;i < n;i++)
	    {
	        cin >> x;
	        b.push_back(x);
	    }
	    max1=*max_element(a.begin(),a.end());
	    max2=*max_element(b.begin(),b.end());
	    if(max1==max2)
	    {
	        cout<<"NO"<<endl;
	    }
	    else
	    {
	        cout<<"YES"<<endl;
	    }
	}
	
	    
	   return 0;
}
