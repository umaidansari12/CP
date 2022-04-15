#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
	int parent;
	int rank;
};


int find(vector<node>&dsuf, int x)
{
	if (dsuf[x].parent == -1)
		return x;
	return dsuf[x].parent = find(dsuf, dsuf[x].parent);
}

void Union(vector<node>&dsuf, int from, int to)
{
	if (dsuf[from].rank < dsuf[to].rank)
	{
		dsuf[from].parent = to;
	}
	else if (dsuf[from].rank > dsuf[to].rank)
	{
		dsuf[to].parent = from;
	}
	else
	{
		dsuf[from].parent = to;
		dsuf[to].rank += 1;

	}
}
bool isCyclic(vector<pair<int, int>>&edges, vector<node>&dsuf, int v)
{
	for (auto i : edges)
	{
		int from = find(dsuf, i.first);
		int to = find(dsuf, i.second);
		if (from == to)
			return true;
		Union(dsuf, from, to);
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
	vector<node> dsuf(v);
	for (int i = 0; i < v; i++)
	{
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}
	vector<pair<int, int>> edges;
	for (int i = 0; i < e; i++)
	{
		cin >> src >> dst;
		edges.push_back(make_pair(src, dst));
	}
	if (isCyclic(edges, dsuf, v))
		cout << "True\n";
	else
		cout << "False\n";


	return 0;
}