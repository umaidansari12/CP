#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	double r1 = double(a.first) / double(a.second);
	double r2 = double(b.first) / double(b.second);
	return r1 > r2;
}

double fractionalKnapsack(vector<pair<int, int>> vw, int n, int w)
{
	double res = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (vw[i].second <= w)
		{
			w -= vw[i].second;
			res += (vw[i].first);
		}
		else
		{
			double r = ((double)vw[i].first / vw[i].second);
			res += (w * r);
			break;
		}
	}
	return res;
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
		int n, w;
		cin >> n >> w;
		vector<pair<int, int>> vw;
		for (int i = 0; i < n; i++)
		{
			int v, we;
			cin >> v >> we;
			vw.push_back(make_pair(v, we));
		}
		/*auto i = vw.begin();
		while (i != vw.end())
		{
			cout << i->first << " " << i->second << endl;
			i++;
		}
		cout << "Done\n";

		i = vw.begin();
		while (i != vw.end())
		{
			cout << i->first << " " << i->second << endl;
			i++;
		}
		cout << "Sorted\n";*/
		sort(vw.begin(), vw.end(), cmp);
		double res = fractionalKnapsack(vw, n, w);
		printf("%.2f\n", res);
	}


	return 0;
}