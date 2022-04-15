#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	map<string, int> m;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (m[s] == 0)
		{
			cout << "OK" << endl;
			m[s]++;
		}
		else
		{
			cout << s << m[s] << endl;
			m[s]++;
		}

	}


	return 0;
}