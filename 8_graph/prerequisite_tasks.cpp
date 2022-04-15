#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkCycle(int node, vector<int> graph[], vector<bool>&vis, vector<bool>&rec)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour])
            {
                if (checkCycle(neighbour, graph, vis, rec))
                    return true;
            }
            else if (rec[neighbour])
                return true;
        }
        rec[node] = false;
        return false;
    }
    bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> graph[N];
        for (auto edge : prerequisites)
        {
            graph[edge.first].push_back(edge.second);
        }
        vector<bool> vis(N, false), rec(N, false);
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, graph, vis, rec))
                    return false;
            }
        }
        return true;
    }
    bool isPossibleBFS(int N, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> graph[N];
        vector<int> inDegree(N, 0);
        for (auto edge : prerequisites)
        {
            graph[edge.first].push_back(edge.second);
            inDegree[edge.second]++;
        }
        queue<int> q;
        for (int node = 0; node < N; node++)
        {
            if (inDegree[node] == 0)
                q.push(node);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto neighbour : graph[node])
            {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        if (cnt == N)
            return true;
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends