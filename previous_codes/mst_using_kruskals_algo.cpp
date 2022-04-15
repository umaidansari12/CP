#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
	int parent;
	int rank;
};

struct edge {
	int src;
	int dst;
	int weight;
};

int find(vector<node>&dsuf, int v)
{
	if (dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf, dsuf[v].parent);
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

void kruskals(vector<node>&dsuf, vector<edge>&edges, int e, int v)
{
	int i = 0, j = 0;
	vector<edge> mst;
	while (i < v - 1 && j < e)
	{
		int from = find(dsuf, edges[j].src);
		int to = find(dsuf, edges[j].dst);
		if (from == to)
		{
			j++;
			continue;
		}
		Union(dsuf, from, to);
		mst.push_back(edges[j]);
		i++;
	}
	for (auto i : mst)
	{
		cout << i.src << " " << i.dst << " " << i.weight << endl;
	}

}

bool cmp(edge a, edge b)
{
	if (a.weight == b.weight)
		return a.src < b.src;
	return a.weight < b.weight;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int v, e, src, dst, weight;
	cin >> v >> e;
	vector<node> dsuf(v);
	for (int i = 0; i < v; i++)
	{
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}
	vector<edge>edges(e);
	for (int i = 0; i < e; i++)
	{
		cin >> src >> dst >> weight;
		edges[i].src = src;
		edges[i].dst = dst;
		edges[i].weight = weight;
	}
	sort(edges.begin(), edges.end(), cmp);
	/*for (auto i : edges)
	{
		cout << i.src << " " << i.dst << " " << i.weight << endl;
	}*/
	kruskals(dsuf, edges, e, v);


	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;
//FIND operation
int find(int v)
{
	if (dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP, int toP)
{
	//fromP = find(fromP);
	//toP = find(toP);

	//UNION by RANK
	if (dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if (dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank += 1;		//Increase rank of parent
	}
}

bool comparator(Edge a, Edge b)
{
	return a.wt < b.wt;
}
/*
void printEdgeList(vector<Edge>& edge_List)
{
	for(auto p: edge_List)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}
*/
void Kruskals(vector<Edge>& edge_List, int V, int E)
{
	//cout<<"edge_List before sort\n";
	//printEdgeList(edge_List);
	sort(edge_List.begin(), edge_List.end(), comparator);
	//cout<<"edge_List after sort\n";
	//printEdgeList(edge_List);

	int i = 0, j = 0;
	while (i < V - 1 && j < E)
	{
		int fromP = find(edge_List[j].src);	//FIND absolute parent of subset
		int toP = find(edge_List[j].dst);

		if (fromP == toP)
		{	++j;	continue;	}

		//UNION operation
		union_op(fromP, toP);	//UNION of 2 sets
		mst.push_back(edge_List[j]);
		++i;
	}
}
//Display the formed MST
void printMST(vector<Edge>& mst)
{
	cout << "MST formed is\n";
	for (auto p : mst)
		cout << "src: " << p.src << "  dst: " << p.dst << "  wt: " << p.wt << "\n";
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin >> E >> V;

	dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for (int i = 0; i < V; ++i)	//Mark all nodes as independent set
	{
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}

	vector<Edge> edge_List;	//Adjacency list
	Edge temp;
	for (int i = 0; i < E; ++i)
	{
		int from, to, wt;
		cin >> from >> to >> wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

	Kruskals(edge_List, V, E);
	printMST(mst);

	return 0;
}

//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices