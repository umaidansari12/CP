#include <bits/stdc++.h>

using namespace std;

vector <int> dynamicArrays(int n,vector<vector <int>>queries)
{
	vector <vector<int>> seqList(n);
	int lastAnswer=0;
	vector <int> l;
	for(int i=0;i<queries.size();i++)
	{
		int index = (queries[i][1]^lastAnswer)%n;
		if(queries[i][0]==1)
		{
			seqList[index].push_back(queries[i][2]);
		}
		else if(queries[i][1]==2)
		{
			lastAnswer=seqList[index][queries[i][2]%seqList[index].size()];
			l.push_back(lastAnswer);
		}
	}
	return l;
}

int main()
{
	int n,q;
	cin>>n>>q;
	vector <vector<int>>queries(q);
	for(int i=0;i<q;i++)
	{
		queries[i].resize(3);
		for(int j=0;j<3;j++)
		{
			cin>>queries[i][j];
		}
	}
	vector <int> res=dynamicArrays(n,queries);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
}
