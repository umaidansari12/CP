#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool compare(string a, string b)
{
	return a + b > b + a;
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
		vector<int> a(n);
		vector<string> s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s[i] = to_string(a[i]);
		}
		sort(s.begin(), s.end(), compare);
		for (auto i : s)
			cout << i;
		cout << endl;


	}


	return 0;
}