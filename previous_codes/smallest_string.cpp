#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool compare(string a, string b)
{
	return a + b < b + a;
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
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (auto i : a)
			cout << i << " ";
		cout << endl;
		sort(a.begin(), a.end(), compare);
		for (string i : a)
			cout << i;
		cout << endl;

	}


	return 0;
}