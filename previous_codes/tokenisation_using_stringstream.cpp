#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	stringstream ss(s);
	string token;
	vector<string> tokens;
	while (getline(ss, token, ' '))
	{
		tokens.push_back(token);
	}
	for (auto i : tokens)
		cout << i << ",";
	cout << endl;

	return 0;
}