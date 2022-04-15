
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m,g;
	cin >> n>>m>>g;	
	vector <int> time(n);
	vector <int> clothes(m);
	vector <int> gap;
	for(int i=0;i<n;i++)
	{
		cin>>time[i];
	}		
	for(int i=0;i<m;i++)
	{
		cin>>clothes[i];
	}
	int count=0;	
	for(int i=1;i<n;i++)
	{
		
		int t=time[i]-time[i-1];
		gap.push_back(t);
	}
	int ma=*max_element(gap.begin(),gap.end());
	for(int j=0;j<m;j++)
		{
			if(clothes[j]<=ma)
			{
				count++;
			}
			
		}
					
	cout << count<<endl;
}

