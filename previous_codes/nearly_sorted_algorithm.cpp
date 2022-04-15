#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		/*Method 1
		sort(a, a + n);
		*/
		priority_queue<int, vector<int>, greater<int>> p(a, a + k);
		int index = 0;
		for (int i = k; i < n; i++)
		{
			a[index++] = p.top();
			p.pop();
			p.push(a[i]);
		}
		while (!p.empty())
		{
			a[index++] = p.top();
			p.pop();
		}
		for (auto i : a)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}