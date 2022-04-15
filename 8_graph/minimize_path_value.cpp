#include <bits/stdc++.h>

using namespace std;

/*
to be solved
Given a weighted undirected graph with N nodes and M edges.The stress
level of a path between two nodes is defined as the weight of the
edge with the maximum value presennt in the path.Given a source
node "source" and a destination node "destination".Find a path with
the minimum stress level.If no such path exists , report -1.

Input : From   to   weight
        1       2   100
        2       3   200
        1       4   10
        4       3   20
        source = 1
        destination = 3
Output : 20

Input : From   to   weight
        1       2   10
        2       3   5
        1       4   3
        4       3   2
        1       5   4
        5       3   6
        source = 1
        destination = 3
Output : 3

Input : From   to   weight
        1       2   10
        source = 1
        destination = 3
Output : -1 , as there is no edge between 1 to 3 , node 3 is not reachable

*/

/*
 * Complete the 'getMinimumStress' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. WEIGHTED_INTEGER_GRAPH graph
 *  2. INTEGER source
 *  3. INTEGER destination
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int getMinimumStress(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<int> graph_weight, int source, int destination) {
    int N = graph_nodes, M = graph_from.size();
    vector<pair<int, int>> graph[N + 1];
    for (int i = 0; i < M; i++) {
        graph[graph_from[i]].push_back({graph_to[i], graph_weight[i]});
        graph[graph_to[i]].push_back({graph_from[i], graph_weight[i]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(N + 1, INT_MAX);
    dist[source] = 0;
    q.push({0, source});
    while (!q.empty()) {
        int distNode = q.top().first;
        int node = q.top().second;
        q.pop();
        int n = graph[node].size();
        for (auto i : graph[node]) {
            int next = i.first;
            int nextdist = i.second;
            ans = max(ans, nextdist);
            if (dist[next] > (nextdist + dist[node]))
            {
                dist[next] = nextdist + dist[node];
                q.push({dist[next], next});
            }
        }
    }
    if (dist[destination] == INT_MAX)
        return -1;
    cout << dist[destination] << endl;                                        int ans = -1;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != 0 and dist[i] != INT_MAX)
            ans = max(ans, dist[i]);
    }
    return ans;

}



void dfs(vector<pair<int, int>> graph[], int node, int dest, vector<bool> &visited, int &ans) {
    if (node == dest)
        return;
    visited[node] = true;
    cout << node << " ";

    int size = graph[node].size();
    for (int i = 0; i < size; i++) {
        if (!visited[graph[node][i].first]) {
            ans = max(ans, graph[node][i].second);
            dfs(graph, graph[node][i].first, dest, visited, ans);
        }
    }
}

int getMinimumStressDFS(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<int> graph_weight, int source, int destination) {
    int N = graph_nodes, M = graph_from.size();
    vector<pair<int, int>> graph[N + 1];
    for (int i = 0; i < M; i++) {
        graph[graph_from[i]].push_back({graph_to[i], graph_weight[i]});
        graph[graph_to[i]].push_back({graph_from[i], graph_weight[i]});
    }
    int result = -1;
    vector<bool> visited(N + 1, false);
    int size = graph[source].size();
    vector<int> res;
    for (int i = 0; i < size; i++) {
        int ans = INT_MIN;
        if (!visited[graph[source][i].first]) {
            dfs(graph, graph[source][i].first, destination, visited, ans);
            res.push_back(ans);
            visited[destination] = false;
        }

    }
    int n = res.size(), ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
        ans = min(ans, res[i]);
    }
    cout << endl;
    return ans;

}

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int graph_nodes;
        cin >> graph_nodes;
        int graph_edges;
        cin >> graph_edges;

        vector<int> graph_from(graph_edges);
        vector<int> graph_to(graph_edges);
        vector<int> graph_weight(graph_edges);

        for (int i = 0; i < graph_edges; i++) {

            int graph_from_temp;
            cin >> graph_from_temp;
            int graph_to_temp;
            cin >> graph_to_temp;
            int graph_weight_temp;
            cin >> graph_weight_temp;

            graph_from[i] = graph_from_temp;
            graph_to[i] = graph_to_temp;
            graph_weight[i] = graph_weight_temp;
        }

        int source;
        cin >> source;
        int destination;
        cin >> destination;

        int result = getMinimumStress(graph_nodes, graph_from, graph_to, graph_weight, source, destination);
        cout << result << endl;
    }


    return 0;
}
