#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> adj[],vector<bool>&vis)
	{
	    vis[node]=true;
	    for(auto neighbour:adj[node])
	    {
	        if(!vis[neighbour])
	        dfs(neighbour,adj,vis);
	    }
	}
	void topoSort(int node,vector<int> adj[],vector<bool>&vis,stack<int>&s)
	{
	    vis[node]=true;
	    for(auto neighbour:adj[node])
	    {
	        if(!vis[neighbour])
	        topoSort(neighbour,adj,vis,s);
	    }
	    s.push(node);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        vector<bool> vis(V,false);
        //sort according to the finishing time
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                topoSort(i,adj,vis,s);
            }
        }
        vector<int> transpose[V];
        //taking the transpose of the graph
        for(int i=0;i<V;i++)
        {
            vis[i]=false;//unmarking the visited nodes to do the dfs again
            for(auto neighbour:adj[i])
            {
                transpose[neighbour].push_back(i);
            }
        }
        int cnt=0;
        //taking the DFS according to the finishing time
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            if(!vis[node])
            {
                cnt++;
                dfs(node,transpose,vis);
            }
        }
        return cnt;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends