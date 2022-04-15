#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool kahn(int n, vector<int> &in, vector<int> a[], vector<int>& res)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int curr = q.top();
		res.push_back(curr);
		q.pop();
		for (int node : a[curr])
		{
			in[node]--;
			if (in[node] == 0)
				q.push(node);
		}
	}

	return res.size() == n;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n, m, x, y;
	cin >> n >> m;
	vector<int> a[n + 1], in(n + 1, 0), res;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		in[y]++;
	}
	if (!kahn(n, in, a, res))
		cout << "Sandro fails.";
	else
	{
		for (int i : res)
			cout << i << " ";
		//cout << endl;
	}


	return 0;
}