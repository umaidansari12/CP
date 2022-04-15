class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<int> degree(n + 1, 0);//degree of the nodes
		vector<vector<bool>> connected(n + 1, vector<bool>(n + 1, false));//creating a undirected graph
		bool found = false;
		int ans = INT_MAX;
		for (auto edge : edges)
		{
			int u = edge[0];
			int v = edge[1];
			degree[u]++;
			degree[v]++;
			connected[u][v] = true;
			connected[v][u] = true;
		}
		for (int u = 0; u <= n; u++)
		{
			for (int v = u + 1; v <= n; v++)
			{
				if (connected[u][v])//if u and v are connected then we move to w
				{
					for (int w = v + 1; w <= n; w++)
					{
						if (connected[u][w] and connected[v][w])// if u w and v w are connected
						{
							found = true;
							ans = min(ans, degree[u] + degree[v] + degree[w] - 6);
						}
					}
				}
			}
		}
		if (found)
			return ans;
		return -1;
	}
};

/*
For each pair, check if they have a common neighbor and calculate their degree.

Update: I initially used adjacency list, but since the number of nodes is limited, we can use a matrix. This speeds up the runtime quite a bit (1,200 ms => 300 ms).

Important optimizations:

t1 > t2 > t3, so we do not check the same triplet twice.
- For that, we can use a directed adjacency list (or matrix).
- In this case, we need to store counts for each node separately.
Use adjacency list with a set to quickly check for the common neighbor.
- Or use an adjacency matrix.
Adjacency List
*/


int minTrioDegree(int n, vector<vector<int>>& edges) {
	vector<set<int>> al(n + 1);
	vector<int> cnt(n + 1);
	int res = INT_MAX;
	for (auto &e : edges) {
		al[min(e[0], e[1])].insert(max(e[0], e[1]));
		++cnt[e[0]];
		++cnt[e[1]];
	}
	for (auto t1 = 1; t1 <= n; ++t1)
		for (auto it2 = begin(al[t1]); it2 != end(al[t1]); ++it2)
			for (auto it3 = next(it2); it3 != end(al[t1]); ++it3)
				if (al[*it2].count(*it3))
					res = min(res, cnt[t1] + cnt[*it2] + cnt[*it3] - 6);
	return res == INT_MAX ? -1 : res;
}

class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<int> degree(n + 1, 0);
		vector<vector<bool>> connected(n + 1, vector<bool>(n + 1, false));
		int ans = INT_MAX;
		for (auto edge : edges)
		{
			int u = edge[0];
			int v = edge[1];
			degree[u]++;
			degree[v]++;
			connected[u][v] = true;
			connected[v][u] = true;
		}
		for (int u = 0; u <= n; u++)
		{
			for (int v = u + 1; v <= n; v++)
			{
				if (connected[u][v])
				{
					for (int w = v + 1; w <= n; w++)
					{
						if (connected[u][w] and connected[v][w])
						{
							ans = min(ans, degree[u] + degree[v] + degree[w] - 6);
						}
					}
				}
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};


/*check all the possible three nodes combinations.
three nodes is trio if every node's degree is larger than 1 and each node is connceted to each other,
then tri_degree = min(degree[i] - 2 + degree[j] - 2 + degree[k] - 2, tri_degree);*/

class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<int> degree(n + 1);
		vector<vector<int> > adj(n + 1, vector<int>(n + 1));
		for (auto &e : edges) {
			++degree[e[0]];
			++degree[e[1]];
			adj[e[0]][e[1]] = 1;
			adj[e[1]][e[0]] = 1;
		}
		int ans = INT_MAX;
		for (int i = 1; i <= n; ++i) {
			if (degree[i] < 2) continue;
			for (int j = i + 1; j <= n; ++j) {
				if (degree[j] < 2) continue;
				if (!adj[i][j]) continue;
				for (int k = j + 1; k <= n; ++k) {
					if (degree[k] < 2) continue;
					if (adj[i][j] && adj[j][k] && adj[k][i]) {
						ans = min(ans, degree[i] - 2 + degree[j] - 2 + degree[k] - 2);
					}
				}
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};