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
		int n;
		cin >> n;
		if (n % 4 == 0) {
			cout << "YES\n";
			// cout << "1 4\n2 3\n";
			vector<int> A, B;
			for (int x = 1, f = 0; x <= n; x += 2, f = !f) {
				if (f)
				{
					A.push_back(x);
					B.push_back(x + 1);
				}
				else
				{
					A.push_back(x + 1);
					B.push_back(x);
				}
			}
			reverse(B.begin(), B.end());
			for (auto i : A)
				cout << i << " ";
			cout << endl;
			for (auto i : B)
				cout << i << " ";
			cout << endl;
			cout << endl;
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}

