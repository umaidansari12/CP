class Solution {
public:
    bool checkCycle(int node, int parent, vector<int> adj[], vector<bool>&vis)
    {
        vis[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                if (checkCycle(neighbour, node, adj, vis))
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }
        return false;
    }
    /*This solution is similar to that mentioned in the offical solution. We will construct the graph by adding edges one after another. After each addition of a new edge, we will do a dfs traversal to check if any cycle has formed. If a cycle is detected, we know that the last edge addition has led to the formation of cycle and hence we will simply return that edge.*/
    /*
    Time Complexity : O(n2), In worst case, we may need n dfs calls with each taking O(n) time complexity.
    Space Complexity : O(n), to maintain graph
    */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();//because it is a tree n edges so n+1 vertices
        vector<int> adj[n + 1]; //n+1 because vertices are 1-based indexing graph creation
        vector<bool> vis(n + 1, false);
        for (auto e : edges)
        {
            fill(vis.begin(), vis.end(), false); // reset the vis array
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            // adding an edge and checking if it creates a cycle or not
            // we need to return the last answer that is creating a cycle
            // initially a tree is given and we need to return the last edges by removing which our graph becomes a tree again i.e acyclic
            if (checkCycle(e[0], adj, vis))
                return e;
        }

        return {}; // un-reachable
    }
};