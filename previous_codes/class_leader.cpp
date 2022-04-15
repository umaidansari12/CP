#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,o;
		cin>>n>>m>>o;
		vector <int> a(n);
		for(int i=1;i<=n;i++)
		{
			a[i-1]=i;
		}
		while(a.size()!=1)
		{
			m=m+o%n;
            auto i=a.begin()+m;
			a.erase(m);
		}
		cout<<a.back()<<endl;
	}


	return 0;
}