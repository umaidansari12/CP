#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
    bool checkCyclic(int node,vector<int> adj[],vector<bool>&vis,vector<bool>&stack)
    {
        vis[node]=true;
        stack[node]=true;
        for(auto neighbour:adj[node])
        {
            if(!vis[neighbour])
            {
                if(checkCyclic(neighbour,adj,vis,stack))
                return true;
            }
            else if(stack[neighbour])
            return true;
        }
        stack[node]=false;
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> vis(V,false);
        vector<bool> stack(V,false);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	    {
	   	        if(checkCyclic(i,adj,vis,stack))
	   	        return true;
	   	    }
	   	}
	   	return false;
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends