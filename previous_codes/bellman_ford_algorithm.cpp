#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
	int src, dst, wt;
};
/*#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dst,wt;
};
int V,E;

void bellmanFord(vector<edge>& Edges)
{
	int parent[V];		//Stores Shortest Path Structure
	int cost_parent[V];	//Cost of the node to parent edge weight
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for(int i=0;i<V-1;++i)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				value[V] = value[U]+wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}
		if(updated==false)
			break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E and updated==true;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
}

int main()
{
	cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	//Now input all E edges
	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges);
	return 0;
}

//TIME COMPLEXITY: O(V.E)*/


bool bellmanFordAlgorithm(vector<edge>&edges, int v, int e)
{
	vector<int> parent(v, -1);
	vector<int> cost_parent(v);
	vector<int> value(v, INT_MAX);
	value[0] = 0;
	bool updated;
	for (int i = 0; i < v - 1; i++)
	{
		updated = false;
		for (int j = 0; j < e; j++)
		{
			int src = edges[j].src;
			int dst = edges[j].dst;
			int wt = edges[j].wt;
			if (value[src] != INT_MAX && value[src] + wt < value[dst])
			{
				parent[dst] = src;
				value[dst] = value[src] + wt;
				cost_parent[dst] = value[dst];
				updated = true;
			}
		}
		if (updated == false)
			break;
	}
	for (int j = 0; j < e && updated == true; j++)
	{
		int src = edges[j].src;
		int dst = edges[j].dst;
		int wt = edges[j].wt;
		if (value[src] != INT_MAX && value[src] + wt < value[dst])
		{
			return true;
		}
	}
	//Print Shortest Path Graph
	for (int i = 1; i < V; ++i)
		cout << "U->V: " << parent[i] << "->" << i << "  Cost to reach " << parent[i] << "from source 0 = " << value[i] << "\n";
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int v, e, src, dst, wt;
		cin >> v >> e;
		vector<edge> edges(e);
		for (int i = 0; i < e; i++)
		{
			cin >> src >> dst >> wt;
			edges[i].src = src;
			edges[i].dst = dst;
			edges[i].wt = wt;
		}
		cout << bellmanFordAlgorithm(edges, v, e) << endl;
	}


	return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
	int src, dst, wt;
};

bool bellmanFordAlgorithm(vector<edge>&edges, int v, int e)
{
	vector<int> parent(v, -1);
	vector<int> cost_parent(v);
	vector<int> value(v, INT_MAX);
	value[0] = 0;
	bool updated;
	for (int i = 0; i < v - 1; i++)
	{
		updated = false;
		for (int j = 0; j < e; j++)
		{
			int src = edges[j].src;
			int dst = edges[j].dst;
			int wt = edges[j].wt;
			if (value[src] != INT_MAX && value[src] + wt < value[dst])
			{
				parent[dst] = src;
				value[dst] = value[src] + wt;
				cost_parent[dst] = value[dst];
				updated = true;
			}
		}
		if (updated == false)
			break;
	}
	for (int j = 0; j < e ; j++)
	{
		int src = edges[j].src;
		int dst = edges[j].dst;
		int wt = edges[j].wt;
		if (value[src] != INT_MAX && value[src] + wt < value[dst])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int v, e, src, dst, wt;
		cin >> v >> e;
		vector<edge> edges(e);
		for (int i = 0; i < e; i++)
		{
			cin >> src >> dst >> wt;
			edges[i].src = src;
			edges[i].dst = dst;
			edges[i].wt = wt;
		}
		cout << bellmanFordAlgorithm(edges, v, e) << endl;
	}


	return 0;
}