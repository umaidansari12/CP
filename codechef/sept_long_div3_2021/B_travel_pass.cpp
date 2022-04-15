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
	while (t--) {
		int n, a, b, x;
		long long int sum = 0;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
				sum += a;
			else if (s[i] == '1')
				sum += b;
		}
		cout << sum << endl;


	}


	return 0;
}