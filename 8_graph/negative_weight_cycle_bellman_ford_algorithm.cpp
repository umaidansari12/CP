#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
		// Code here
		vector<int> dist(n, INT_MAX); //create a distance array initialized to INT_MAX
		dist[0] = 0; //source rechable at distance 0
		//relax all the edges (n-1) times
		for (int i = 0; i < (n - 1); i++)
		{
			//bool update = true; take a boolean variable to check if all the edges are relaxed and no update is there so we break out of the loop
			for (auto edge : edges)
			{
				int u = edge[0];
				int v = edge[1];
				int wt = edge[2];
				//if dist[u] is reached and dist[u]+wt is less than previous then uupdate
				if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
				{
					dist[v] = dist[u] + wt;
					update = false;
				}
			}
			// if(update)
			// break;
		}
		for (auto edge : edges)
		{
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
			{
				return true;
			}
		}
		return false;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x, y, z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends