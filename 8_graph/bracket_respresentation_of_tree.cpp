#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<int> graph[], char root, vector<bool> &visited) {
	visited[root - 'A'] = true;
	cout << "(" << (root);
	for (int i = 0; i < (int)graph[root - 'A'].size(); i++) {
		if (!visited[graph[root - 'A'][i]]) {
			dfs(graph, (graph[root - 'A'][i]) + 'A', visited);
		}
	}

	cout << ")";

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char x, y, root;

		// vector<char> graph[255];
		// for (int i = 0; i < n; i++) {
		// 	cin >> x >> y;
		// 	graph[x].push_back(y);
		// }
		// for (int i = 0; i < 255; i++) {
		// 	cout << i << "->";
		// 	for (int j = 0; j < graph[i].size(); j++) {
		// 		cout << char(graph[i][j]) << " ";
		// 	}
		// 	cout << endl;
		// }
		vector<int> graph[26];
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			graph[x - 'A'].push_back(y - 'A');
		}

		/*for (int i = 0; i < 26; i++) {
			cout << i << "->";
			for (int j = 0; j < graph[i].size(); j++) {
				cout << char(graph[i][j] + 'A') << " ";
			}
			cout << endl;
		}*/
		cin >> root;
		vector<bool> visited(26, 0);
		dfs(graph, root, visited);
	}


	return 0;
}