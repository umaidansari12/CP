/*
#include <iostream>

using namespace std;

int main() {
    int t,n,k,j;

    cin >> t;
	for(int i=0;i<t;i++)
	{
	    int count=0;
	    cin >> n;
	    cin >> k;
	    int *a=new int[n];
	    for(j=0;j<n;j++)
	    {
	        cin>>*(a+j);
	    }
	    j=0;
	   for(j=0;j<n && *(a+j)<k;j++)
	    {
	        for(int b=0;b<n;b++)
	            {
	                *(a+b)=*(a+b)+1;
	            }
            j=0;
	        count++;
	        }
	   cout<<count<<endl;
	}
	return 0;
	}
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t,n;
	char prev;
	cin >> t;
	vector<int> a(2);
	for(int i=0;i<t;i++)
	{
        a[0]=0;
        a[1]=0;
	    cin >> n;
	    char s[n];
	    cin >> s;
	    prev='I';
	    for(int j=0;j<n;j++)
	    {
	        if(s[j]=='L'&& (prev!='L' && prev !='R'))
	            {
	                 a[0]--;
	                 prev='L';
	            }
	        else if(s[j]=='R'&& (prev!='R'&&prev!='L'))
	            {
	                 a[0]++;
	                 prev='R';
	            }
	       else if(s[j]=='U'&& (prev!='U'&&prev!='D'))
	            {
	                 a[1]++;
	                 prev='U';
	            }
	       else if(s[j]=='D'&& (prev!='D'&&prev!='U'))
	            {
	                 a[1]--;
	                 prev='R';
	            }
	    }
	    	for(int k=0;k<a.size();k++)
	{
	    cout<<a[k]<<" ";
	}
	cout<<endl;
	a.clear();
	}

	return 0;
}
