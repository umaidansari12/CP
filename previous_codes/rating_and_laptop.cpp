#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int price[n], rating[n];
	vector<pair<int, int>> laptop(n);
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
		cin >> rating[i];
		laptop[i] = make_pair(price[i], rating[i]);
	}

	sort(laptop.begin(), laptop.end(), [](pair<int, int> a, pair<int, int> b) {
		a.first <= b.first;
	})

	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;

	}



	return 0;
}