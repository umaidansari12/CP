#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool parathesisChecker(string s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (st.empty())
				return false;
			char c = st.top();
			st.pop();
			if (s[i] == ')' && c != '(')
				return false;
			else if (s[i] == '}' && c != '{')
				return false;
			else if (s[i] == ']' && c != '[')
				return false;
		}
	}
	return (st.empty()) ? true : false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		if (parathesisChecker(s))
			cout << "balanced\n";
		else
			cout << "not balanced\n";
	}

	return 0;
}