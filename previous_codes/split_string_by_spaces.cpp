#include <bits/stdc++.h>

using namespace std;
using ll = long long;


std::vector<std::string> string_split(const std::string & str) {
	std::vector<std::string> result;
	std::istringstream iss(str);
	for (std::string s; iss >> s; )
	{
		if (s[s.size() - 1] == ',' or s[s.size() - 1] == '.')
			result.push_back(s.substr(0, s.size() - 1));
		else
			result.push_back(s);
	}

	return result;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	vector<string> r = string_split(s);
	for (auto i : r)
		cout << i << endl;
	return 0;
}