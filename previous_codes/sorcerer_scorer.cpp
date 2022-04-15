#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> count_Score(vector<int> a, vector<int> b, int n, int m)
{
	vector<int> score;
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] <= b[i])
				count++;
		}
		score.push_back(count);
	}
	return score;
}

vector<int> countScore(vector<int> a, vector<int> b, int n, int m)
{
	vector<int> score;
	//sort(a.begin(), a.end());
	//sort(b.begin(), b.end());
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		int j = 0;
		while (a[j] <= b[i] && j < n)
		{
			count++;
			j++;
		}
		score.push_back(count);
	}

	return score;
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
		int n, m;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i <  m ; i++)
		{
			cin >> b[i];
		}
		vector<int> res = countScore(a, b, n, m);
		cout << "RESULT : ";
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}


	return 0;
}