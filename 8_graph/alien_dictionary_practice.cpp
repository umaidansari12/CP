#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void topoSort(vector<int> adj[], int node, vector<int> &visited, stack<int> &topo) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                topoSort(adj, it, visited, topo);
            }
        }
        topo.push(node);
    }
public:
    string findOrder(vector<string> &words) {
        // code here
        vector<int> adj[26];

        int _size = words.size();
        vector<int> visited(26, 1);

        for (int i = 0; i < _size - 1; i++) {
            int min_size = min(words[i].size(), words[i + 1].size());
            for (int ptr = 0; ptr < min_size; ptr++) {
                if (words[i][ptr] != words[i + 1][ptr]) {
                    adj[words[i][ptr] - 'a'].push_back(words[i + 1][ptr] - 'a');
                    visited[words[i][ptr] - 'a'] = 0;
                    visited[words[i + 1][ptr] - 'a'] = 0;
                    break;
                }
                else {
                    visited[words[i][ptr] - 'a'] = 0;
                }
            }
        }

        for (int i = 0; i < _size; i++) {
            for (int ptr = 0; ptr < words[i].size(); ptr++) {
                visited[words[i][ptr] - 'a'] = 0;
            }
        }


        vector<int>indegree(26, -1);
        for (int node = 0; node < 26; node++) {
            if (!visited[node]) {
                if (indegree[node] == -1)
                    indegree[node] = 0;
                else
                    indegree[node]++;
            }
            for (auto neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    if (indegree[node] == -1)
                        indegree[node]++;
                    indegree[neighbour]++;
                }
            }
        }


        for (int node = 0; node < 26; node++) {
            cout << indegree[node] << "," << visited[node] << "," << node << "->";
            for (auto neighbour : adj[node]) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
        stack<int> topo;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 and !visited[i])
                topoSort(adj, i, visited, topo);
        }
        string ans = "";
        while (!topo.empty()) {
            ans += (topo.top() + 'a');
            topo.pop();
        }
        // cout << ans << endl;
        return ans;

    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<string> words(n);

        for (int i = 0; i < n; i++)
            cin >> words[i];

        Solution ob = Solution();
        string res = ob.findOrder(words);
        if (res.empty())
            cout << "-" << endl;
        else
            cout << res << endl;

    }
}
