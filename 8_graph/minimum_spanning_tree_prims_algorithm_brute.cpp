#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    // Function to construct and print MST for
    // a graph represented using adjacency
    // matrix representation, with V vertices.
    // graph[i][j] = weight if edge exits else 0
    int selectMin(vector<int>&value, bool *setMST)
    {
        int vertex = -1, minimum = INT_MAX;
        for (int i = 0; i < value.size(); i++)
        {
            if (!setMST[i] && value[i] < minimum)
            {
                vertex = i;
                minimum = value[i];
            }
        }
        return vertex;
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V + 1, INT_MAX); //to store the minimum edge weight that is coming to that node
        vector<int> parent(V + 1, -1); //parent - child relationship constructed using the parent array
        vector<bool> mst(V + 1, false); //mst array which tells whether the node is part of the mst or not if false not a part otherwise true that is a part of mst

        key[0] = 0; //it takes 0 edge weight cost to reach node 0 or start from node 0 to make it mst
        parent[0] = -1; //0 is the root element in the tree and its parent is 0
        for (int edge = 0; edge < V; edge++) // we need to include only (n-1) edges into our mst so we are running loop from 0 to n-1 not n
        {
            int min_edge = INT_MAX, currVertex;
            for (int i = 0; i <= V; i++)
            {
                //checking if the node is not a part of mst and it has edge  which has minimum cost then take that node into account and make it a part of MST
                if (mst[i] == false and key[i] < min_edge)
                {
                    min_edge = key[i];
                    currVertex = i;
                }
            }
            //int u = selectMin(value, setMST);
            // marking true to make the node which has minimum edge
            mst[currVertex] = true;
            //traversing the adjacent of current node and placing it in the key which has lower edge cost to reach
            //traversing the adjacent of current node and check if any adjacent node is reachable in lower edge cost as previous
            for (auto neighbour : adj[currVertex])
            {
                int node = neighbour[0];
                int weight = neighbour[1];
                //if the adjacent node is not a part of mst and it is reachable in lower edge cost then update edge cost in key and also mark it as a child of currVertex because it is reached at that cost from currVertex
                if (mst[node] == false and weight < key[node])
                {
                    key[node] = weight;
                    parent[node] = currVertex;
                }
            }
        }
        int sum = 0;
        for (int i = 1; i <= V; i++) //calculating edge weights
        {
            if (key[i] != INT_MAX)
            {
                sum += key[i];
            }
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends


/*

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin >> N >> m;
    vector<pair<int,int> > adj[N];

    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1;
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    {

        int mini = INT_MAX, u;

        for (int v = 0; v < N; v++)
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;

        mstSet[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }

    }


    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i <<" \n";
    return 0;
}

*/