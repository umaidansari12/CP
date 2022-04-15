#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> adj[100001];
int dist[100001], vis[100001];

vector<int> primes;

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isValid(int a, int b)
{
	int cnt = 0;
	while (a > 0)
	{
		if (a % 10 != b % 10)
			cnt++;
		a /= 10;
		b /= 10;
	}
	if (cnt == 1)
		return true;
	else
		return false;
}
void buildgraph()
{
	for (int i = 1000; i <= 9999; i++)
		if (isPrime(i))
			primes.push_back(i);
	for (int i = 0; i < primes.size(); i++)
		for (int j = i + 1; j < primes.size(); j++)
		{
			if (isValid(primes[i], primes[j]))
			{
				adj[primes[i]].push_back(primes[j]);
				adj[primes[j]].push_back(primes[i]);
			}
		}
}

void bfs(int src)
{
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	vis[src] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i : adj[curr])
		{
			if (vis[i] == 0)
			{
				vis[i] = 1;
				dist[i] = 1 + dist[curr];
				q.push(i);
			}
		}
	}
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T, a, b;
	cin >> T;

	buildgraph();
	while (T--)
	{
		//int a, b;
		cin >> a >> b;
		for (int i = 1000; i <= 9999; i++)
			dist[i] = -1, vis[i] = 0;
		bfs(a);
		if (dist[b] == -1)
			cout << "Impossible\n";
		else
			cout << dist[b] << endl;
	}


	return 0;
}