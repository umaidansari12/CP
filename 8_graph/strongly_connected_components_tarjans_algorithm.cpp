#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to return a list of lists of integers denoting the members
    //of strongly connected components in the given graph.

    void dfs(int curr, int par, vector<int> adj[], vector<bool>&vis, vector<int>&low, vector<int>&disc, int &_time, stack<int> &s, vector<vector<int>>& ans, vector<bool> &inStack)
    {
        vis[curr] = true;
        disc[curr] = low[curr] = _time++;
        inStack[curr] = true;
        s.push(curr);
        for (auto neighbour : adj[curr])
        {
            if (!vis[neighbour])
            {
                dfs(neighbour, curr, adj, vis, low, disc, _time, s, ans, inStack);
                low[curr] = min(low[curr], low[neighbour]);
            }
            else if (inStack[neighbour])
            {
                low[curr] = min(low[curr], disc[neighbour]);
            }
        }
        if (low[curr] == disc[curr])
        {
            vector<int> temp;
            while (s.top() != curr and !s.empty()) {
                temp.push_back(s.top());
                inStack[s.top()] = false;
                s.pop();
            }
            if (!s.empty())
            {
                temp.push_back(s.top());
                inStack[s.top()] = false;
                s.pop();
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<vector<int>> ans;
        vector<bool> vis(V, false);
        vector<int> disc(V, 0);
        vector<int> low(V, 0);
        stack<int> s;
        vector<bool> inStack(V, false);
        int _time = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, low, disc, _time, s, ans, inStack);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        // map<int,vector<int>> m;
        // for(int i=0;i<V;i++)
        // {
        //     m[low[i]].push_back(i);
        // }
        // vector<vector<int>> r;
        // for(auto i:m)
        // r.push_back(i.second);
        // return r;

    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                if (j == ptr[i].size() - 1)
                    cout << ptr[i][j];
                else
                    cout << ptr[i][j] << " ";
            }
            cout << ',';
        }
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends