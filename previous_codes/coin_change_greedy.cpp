#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int coinChangeGreedy(vector<int> coin, int m, int v)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (v >= coin[i])
		{
			count += (v / coin[i]);
			v %= coin[i];
		}
	}
	return count;
}

void findMin(int V)
{
	int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int n = 9;
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--)
	{
		while (v >= deno[i])
		{
			v -= deno[i];
			ans.push_back(deno[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int v, m;
		cin >> v >> m;
		vector<int> coin(m);
		for (int i = 0; i < m; i++)
			cin >> coin[i];
		cout << coinChangeGreedy(coin, m, v) << endl;
	}


	return 0;
}