#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int selectMin(vector<int>&value, bool *setMST)
{
	int vertex = -1, minimum = INT_MAX;
	for (int i = 1; i < value.size(); i++)
	{
		if (!setMST[i] && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

int findMST(vector<vector<int>>&graph, int v)
{
	vector<int> parent(v, -1);
	vector<int> value(v, INT_MAX);
	parent[0] = parent[1] = -1;
	value[1] = 0;
	bool setMST[v] = {false};
	for (int i = 0; i < v - 1; i++)
	{
		int u = selectMin(value, setMST);
		setMST[u] = true;
		for (int j = 0; j < v; j++)
		{
			if (graph[u][j] != 0 && (!setMST[j]) && graph[u][j] < value[j])
			{
				value[j] = graph[u][j];
				parent[j] = u;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i < v; i++)
		sum += value[i];
	//cout << sum << endl;
	return sum;
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
		vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));
		/*for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				cin >> graph[i][j];*/
		for (int i = 0; i < e; i++)
		{
			cin >> src >> dst >> wt;
			graph[src][dst] = wt;
			graph[dst][src] = wt;
		}
		cout << findMST(graph, v + 1) << endl;


	}



	return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

int selectMinVertex(vector<int>& value, vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	for (int i = 0; i < V; ++i)
	{
		if (setMST[i] == false && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void findMST(int graph[V][V])
{
	int parent[V];		//Stores MST
	vector<int> value(V, INT_MAX);	//Used for edge relaxation
	vector<bool> setMST(V, false);	//TRUE->Vertex is included in MST

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Form MST with (V-1) edges
	for (int i = 0; i < V - 1; ++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value, setMST);
		setMST[U] = true;	//Include new Vertex in MST

		//Relax adjacent vertices (not yet included in MST)
		for (int j = 0; j < V; ++j)
		{
			/* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
			if (graph[U][j] != 0 && setMST[j] == false && graph[U][j] < value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print MST
	for (int i = 1; i < V; ++i)
		cout << "U->V: " << parent[i] << "->" << i << "  wt = " << graph[parent[i]][i] << "\n";
}

int main()
{
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
		{4, 0, 6, 3, 4, 0},
		{6, 6, 0, 1, 8, 0},
		{0, 3, 1, 0, 2, 3},
		{0, 4, 8, 2, 0, 7},
		{0, 0, 0, 3, 7, 0}
	};

	findMST(graph);
	return 0;
}

//TIME COMPLEXITY: O(V^2)
@ForgottenProgramme
