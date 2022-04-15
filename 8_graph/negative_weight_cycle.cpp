
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

/*
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges;
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;


    int inf = 10000000;
    vector<int> dist(N, inf);

    dist[src] = 0;

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0;
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

/*
6 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
0
*/