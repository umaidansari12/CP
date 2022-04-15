#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char *encode(char *src)
{
	//Your code here
	int count = 0, n = strlen(src), j = 0;
	char *res = (char*)malloc(((n * 2) + 1) * sizeof(char));
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		while (i < n - 1 && src[i] == src[i + 1])
		{
			count++;
			i++;
		}
		res[j++] = src[i];
		res[j++] = (count + '0');
	}
	//res[j++]='\0';
	return res;
}



int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string s, res = "";
		cin >> s;
		unordered_map<char, int> count;
		for (int i = 0; i < s.size(); i++)
		{
			if (count[s[i]] == 0)
				res += s[i];
			count[s[i]]++;
			if (s[i] != s[i + 1])
				res += to_string(count[s[i]]);

		}
		cout << res << endl;
	}


	return 0;
}