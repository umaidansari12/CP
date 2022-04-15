#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	/*vector<bool> prime(100001,true);
	prime[0]=prime[1]=false;
	for(int i=2;i*i<=100000;i++)
	{
	    if(prime[i]==true)
	    {
	    for(int j=i*i;j<=100000;j+=i)
	    {
	        prime[j]=false;
	    }
	    }
	}*/
	while (T--)
	{
		int n;
		cin >> n;
		/*bool f=false;
		for(int i=2;i<=100000;i++)
		{
		    if(prime[i])
		    {
		   // cout<<i<<" ";
		        if(prime[n-i])
		        {
		            //cout<<n-i<<endl;
		            f=true;
		            break;
		        }
		    }
		}*/
		if (n > 2)
			cout << "Deepa\n";
		else
			cout << "Arjit\n";

	}
	return 0;
}