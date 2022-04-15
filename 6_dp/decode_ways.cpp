#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void decodeWays(string s, int idx, string res, map<string, string>& m, int &cnt)
{
	if (idx == s.size())
	{
		stringstream ss(res);
		string token;
		bool flag = false;
		while (getline(ss, token, ' '))
		{
			if (m.find(token) == m.end())
			{
				flag = true;
				break;
			}
			//cout << res << endl;
		}
		if (!flag)
			cnt++;
		return;
	}
	decodeWays(s, idx + 1, res + s[idx], m, cnt);
	decodeWays(s, idx + 1, res + s[idx] + " ", m, cnt);
}

class Solution {
public:
	int numDecodings(string s) {
		return s.empty() ? 0 : numDecodings(0, s);
	}
	int numDecodings(int p, string& s) {
		int n = s.size();
		if (p == n) return 1;
		if (s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
		int res = numDecodings(p + 1, s);
		if ( p < n - 1 && (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7'))) res += numDecodings(p + 2, s);
		return res;
	}
	int numDecodings(string s) {
		int n = s.size();
		vector<int> mem(n + 1, -1);
		mem[n] = 1;
		return s.empty() ? 0 : num(0, s, mem);
	}
	int num(int i, string &s, vector<int> &mem) {
		if (mem[i] > -1) return mem[i];
		if (s[i] == '0') return mem[i] = 0;
		int res = num(i + 1, s, mem);
		if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) res += num(i + 2, s, mem);
		return mem[i] = res;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		map<string, string> m;
		m["1"] = 'A';
		m["2"] = 'B';
		m["3"] = 'C';
		m["4"] = 'D';
		m["5"] = 'E';
		m["6"] = 'F';
		m["7"] = 'G';
		m["8"] = 'H';
		m["9"] = 'I';
		m["10"] = 'J';
		m["11"] = 'K';
		m["12"] = 'L';
		m["13"] = 'M';
		m["14"] = 'N';
		m["15"] = 'O';
		m["16"] = 'P';
		m["17"] = 'Q';
		m["18"] = 'R';
		m["19"] = 'S';
		m["20"] = 'T';
		m["21"] = 'U';
		m["22"] = 'V';
		m["23"] = 'W';
		m["24"] = 'X';
		m["25"] = 'Y';
		m["26"] = 'Z';
		int cnt = 0;
		vector<string> res;
		decodeWays1(s, 0, "", m, cnt);
		cout << cnt / 2 << endl;
	}

	return 0;
}