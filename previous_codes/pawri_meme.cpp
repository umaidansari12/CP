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
	while (t--)
	{
		string str;
		cin >> str;
		for (int i = 0; i + 4 < str.length(); i++)
		{
			if (str.substr(i, 5) == "party")
			{
				str[i + 2] = 'w';
				str[i + 3] = 'r';
				str[i + 4] = 'i';
			}
		}
		/*size_t index = 0;
		while (true) {*/
		/* Locate the substring to replace. */
		/*index = str.find("party", index);
		if (index == std::string::npos) break;*/

		/* Make the replacement. */
		/*str.replace(index, 5, "pawri");*/

		/* Advance index forward so the next iteration doesn't pick it up as well. */
		/*index += 5;
		}*/
		cout << str << endl;
	}

	return 0;
}