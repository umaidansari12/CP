#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int find(vector<int>&parent, int x)
{
	if (parent[x] == -1)
		return x;
	return find(parent, parent[x]);
}

void Union(vector<int>&parent, int x, int y)
{
	//int from = find(parent, x);
	//int to = find(parent, y);
	parent[x] = y;
}

bool isCyclic(vector<pair<int, int>>&edges, int v)
{
	vector<int> parent(v, -1);
	for (auto i : edges)
	{
		int from = find(parent, i.first);
		int to = find(parent, i.second);
		if (from == to)
			return true;
		Union(parent, from, to);
	}
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int v, e, src, dst;
	cin >> v >> e;
	vector<pair<int, int>> edges;
	for (int i = 0; i < e; i++)
	{
		cin >> src >> dst;
		edges.push_back(make_pair(src, dst));
	}
	if (isCyclic(edges, v))
		cout << "TRUE\n";
	else
		cout << "FALSE\n";


	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

vector<int> dsuf;
//FIND operation
int find(int v)
{
	if(dsuf[v]==-1)
		return v;
	return find(dsuf[v]);
}

void union_op(int fromP,int toP)
{
	fromP = find(fromP);
	toP = find(toP);
	dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int,int>>& edge_List)
{
	for(auto p: edge_List)
	{
		int fromP = find(p.first);	//FIND absolute parent of subset
		int toP = find(p.second);

		if(fromP == toP)
			return true;

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
	}
	return false;
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	dsuf.resize(V,-1);	//Mark all vertices as separate subsets with only 1 element
	vector<pair<int,int>> edge_List;	//Adjacency list
	for(int i=0;i<E;++i)
	{
		int from,to;
		cin>>from>>to;
		edge_List.push_back({from,to});
	}

	if(isCyclic(edge_List))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";

	return 0;
}

//TIME COMPLEXITY: O(E.V)*/