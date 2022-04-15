#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void minPair(vector<int> a, vector<int> b)
{
	sort(b.begin(), b.end());
	int p1 = -1, p2 = -1, diff = INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		auto lb = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (lb >= 1 and a[i] - b[lb - 1] < diff)
		{
			diff = a[i] - b[lb - 1];
			p1 = b[lb - 1];
			p2 = a[i];
		}
		if (lb != b.size() and b[lb] - a[i] < diff)
		{
			diff = b[lb] - a[i];
			p1 = a[i];
			p2 = b[lb];
		}
	}
	cout << p1 << " " << p2 << endl;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		minPair(a, b);
	}


	return 0;
}