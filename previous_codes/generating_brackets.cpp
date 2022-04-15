#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool checkParanthesis(string x)
{
	stack<char> s;
	for (auto i : x)
	{
		if (s.empty() && i == ')')
			return false;
		else if (!s.empty() && i == ')')
		{
			char ch = s.top();
			s.pop();
		}
		if (i == '(')
			s.push(i);
	}
	return s.empty();
}


void generateBrackets(int n, vector<string> &brackets, string s, int open, int close)
{
	if (s.size() == (2 * n))
	{
		brackets.push_back(s);
		return;
	}
	if (open < n)
		generateBrackets(n, brackets, s + "(", open + 1, close);
	if (close < open)
		generateBrackets(n, brackets, s + ")", open, close + 1);
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
		vector<string> brackets;
		generateBrackets(n, brackets, "", 0, 0);
		for (auto i : brackets)
			cout << i << "\n";
		cout << endl;

	}

	return 0;
}