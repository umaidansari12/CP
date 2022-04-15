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
		string s1, s2;
		cin >> s1 >> s2;
		/*s1.erase(remove(s1.begin(), s1.end(), '.'), s1.end());
		s2.erase(remove(s2.begin(), s2.end(), '.'), s2.end());
		int n1 = stoi(s1);
		int n2 = stoi(s2);
		cout << n1 << " " << n2 << endl;*/
		int n1 = 0, n2 = 0;
		int f = 0;
		for (int i = 0, j = 0; i < s1.size() || j < s2.size();)
		{
			while (i < s1.size() && s1[i] != '.')
				n1 = n1 * 10 + (s1[i++] - '0');
			while (j < s2.size() && s2[j] != '.')
				n2 = n2 * 10 + (s2[j++] - '0');
			if (n1 < n2)
			{
				f = -1;
				break;
			}
			else if (n1 > n2)
			{
				f = 1;
				break;
			}
			n1 = n2 = 0;
			i++; j++;
		}
		cout << f << endl;

	}

	return 0;
}

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int n1 = 0, n2 = 0;
		for (int i = 0, j = 0; i < version1.size() || j < version2.size();)
		{
			while (i < version1.size() && version1[i] != '.')
			{
				n1 = n1 * 10 + (version1[i] - '0');
				i++;
			}
			while (j < version2.size() && version2[j] != '.')
			{
				n2 = n2 * 10 + (version2[j] - '0');
				j++;
			}
			if (n1 < n2)
				return -1;
			else if (n1 > n2)
				return 1;
			n1 = n2 = 0;
			i++;
			j++;
		}

		return 0;

	}
};