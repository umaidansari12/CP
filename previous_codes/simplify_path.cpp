#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	string simplifyPath(string path) {
		stringstream ss(path);
		string token;
		stack<string> tokens;
		while (getline(ss, token, '/'))
		{
			if (!tokens.empty() and token == "..")
			{
				tokens.pop();
			}
			else if (token == "." or token == "" or token == ".." or token == "-")
			{
				continue;
			}
			else
			{
				tokens.push(token);
			}
		}
		list<string> ans;
		while (!tokens.empty())
		{
			ans.push_front(tokens.top());
			tokens.pop();
		}
		path = "/";
		for (auto i : ans)
		{
			string p = "";
			if (i != "")
				p = i + "/";
			path += (p);
		}

		if (path.size() > 1)
			return path.substr(0, path.size() - 1);
		return path;
	}
};

string Solution::simplifyPath(string path) {
	stringstream ss(path);
	string token;
	stack<string> tokens;
	while (getline(ss, token, '/'))
	{
		if (!tokens.empty() and token == "..")
		{
			tokens.pop();
		}
		else if (token == "." or token == "" or token == ".." or token == "-")
		{
			continue;
		}
		else
		{
			tokens.push(token);
		}
	}
	deque<string> ans;
	while (!tokens.empty())
	{
		ans.push_front(tokens.top());
		tokens.pop();
	}
	path = "/";
	for (auto i : ans)
	{
		string p = "";
		if (i != "")
			p = i + "/";
		path += (p);
	}

	if (path.size() > 1)
		return path.substr(0, path.size() - 1);
	return path;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		//cout << s << endl;
		string path = "/";
		stringstream ss(s);
		string token;
		stack<string> tokens;
		list<string> ans;
		//cout << token << endl;
		while (getline(ss, token, '/'))
		{
			//cout << token << endl;
			if (!tokens.empty() and token == "..")
				tokens.pop();
			else if (token == "." or token == "" or token == "..")
				continue;
			else
				tokens.push(token);
		}
		while (!tokens.empty())
		{
			ans.push_front(tokens.top());
			//cout << tokens.top() << endl;
			tokens.pop();
		}
		for (auto i : ans)
		{
			string p = "";
			if (i != "")
				p = i + "/";
			path += (p);
		}
		if (path.length() > 1)
			cout << path.substr(0, path.length() - 1) << endl;
		else
			cout << path << endl;

		//cout << "end\n";
	}


	return 0;
}