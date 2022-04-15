#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*class Solution {
public:
	string reverseWords(string s) {
		string token = "";
		stack<string> a;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				remove(token.begin(), token.end(), ' ');
				a.push(token);
				token = "";
			}
			else
			{
				token += s[i];
			}
		}
		remove(token.begin(), token.end(), ' ');
		a.push(token);
		token = "";
		while (!a.empty())
		{
			//string str=a.top();
			//remove(str.begin(),str.end(),' ');
			if (a.size() != 1)
				token += a.top() + " ";
			else
				token += a.top();
			a.pop();
		}
		return token;

	}
};
*/

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin.ignore();
		getline(cin, s, '\n');
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		//remove(s.begin(), s.end(), ' ');
		//s.resize(11);
		cout << s;
		/*vector<string> a;
		string token = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				a.push_back(token);
				a.push_back(" ");
				token = "";
			}
			else
			{
				token += s[i];
			}
		}
		a.push_back(token);
		for (int i = a.size() - 1; i >= 0; i--)
			cout << a[i];
		cout << endl;*/
	}
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		char* s;
		cin >> s;
		vector<char*> a;
		char *token = strtok(s, ".");
		while (token != NULL)
		{
			a.push_back(token);
			token = strtok(NULL, ".");
		}
		for (int i = a.size() - 1; i >= 0; i--)
			cout << a[i] << ".";
		cout << endl;
	}
	return 0;
}
*/