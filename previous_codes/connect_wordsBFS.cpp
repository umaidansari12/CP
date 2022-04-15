#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Think of words having difference in only one character as adjacent nodes and solve using BFS algorithm.
 ie- use a queue to keep track of adjacent nodes. */

bool isValid(string a, string b)
{
	int c = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			c++;
	}
	return (c <= 1);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<string> a(n, "");
		vector<int> adj[n];
		vector<int> dis(n, -1);
		vector<int> vis(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (isValid(a[i], a[j]))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		/*for (string i : a)
			cout << s << " ";
		cout << endl;*/
		string s, t;
		int src = -1;
		cin >> s >> t;
		int lvl = 0;
		for (int i = 0; i < n; i++)
		{
			if (s.compare(a[i]) == 0)
			{
				src = i;
				break;
			}
			else if (isValid(s, a[i]))
			{
				lvl++;
				src = i;
				break;
			}

		}
		//cout << s << " " << t << endl;
		queue<int> q;
		q.push(src);
		dis[src] = 0;
		vis[src] = 1;
		while (!q.empty())
		{
			int curr = q.front();
			lvl++;
			q.pop();
			for (int i : adj[curr])
			{
				if (vis[i] == 0)
				{
					vis[i] = 1;
					dis[i] = 1 + dis[curr];
					q.push(i);
				}
			}
		}
		cout << lvl << endl;
	}


	return 0;
}