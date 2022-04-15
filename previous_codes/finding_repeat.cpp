#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void missing(vector <int> a,int n)
{
    vector <int> b(100000);
    for(int i=0;i<(2*n)+2;i++)
    {
        b[a[i]]++;
    }
    for(int i=0;i<100000;i++)
    {
        if(b[i]!=2)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void missingOne(vector <int> a,int n)
{
    sort(a.begin(),a.end());
    for(int i=0;i<(2*n)+2;i++)
    {
        if(i<=(2*n))
        {
            if(a[i]!=a[i-1] && a[i]!=a[i+1])
            {
                cout<<a[i]<<" ";
            }
        }
        else
        {
            if(a[i]!=a[i-1])
            {
                cout<<a[i]<<" ";
            }
        }
            
        /*else if(i==0)
        {
            if(a[i]!=a[i+1])
            {
                cout<<a[i]<<" ";
            }
        }
        else if(i==n-1)
        {
            if(a[i]!=a[i-1])
            {
                cout<<a[i]<<" ";
            }
        }*/
        
    }
    cout<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <int> a(2*n+2);
	    for(int i=0;i<(2*n)+2;i++)
	    {
	        cin>>a[i];
	    }
	    missingOne(a,n);
	    a.clear();
	}
	return 0;
}