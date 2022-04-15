#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool redundantParanthesis(string x)
{
	stack<char> s;
	for (auto ch : x)
	{
		if (ch == ')' or ch == ']' or ch == '}')
		{
			bool found = false;
			char c = ch == ')' ? '(' : (ch == '}' ? '{' : '[');
			cout << c << endl;
			while (!s.empty() && s.top() != c)
			{
				if (s.top() == '+' or s.top() == '-' or s.top() == '*' or s.top() == '/')
					found = true;
				s.pop();
			}
			s.pop();
			if (!found)
				return false;
		}
		s.push(ch);
	}
	return true;
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
		cin >> s;
		if (redundantParanthesis(s))
			cout << "Yes\n";
		else
			cout << "No\n";

	}


	return 0;
}