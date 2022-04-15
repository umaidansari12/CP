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
	while (T--) {
		string s;
		cin >> s;
		int n = s.size(), flag = 0, sign = 1;
		long long int no = 0;
		if (s[0] == '-')
		{
			sign = -1;
			for (int i = 1; i < n; i++)
			{
				if (!isdigit(s[i]))
				{
					cout << -1 << endl;
					flag = 1;
					break;
				}
				no = no * 10 + s[i] - '0';
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (!(s[i] >= '0' && s[i] <= '9'))
				{
					cout << -1 << endl;
					flag = 1;
					break;
				}
				no = no * 10 + s[i] - '0';
			}
		}

		if (!flag)
			cout << sign*no << endl;

	}


	return 0;
}


class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int i = 0, sign = 1;
		while (i + 1 < str.size() && isspace(str[i])) ++i;
		long res = 0;
		if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
		while (i < str.size()) {
			if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
			else return res * sign;
			if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
		}
		return res * sign;
		/*s.erase(remove(s.begin(), s.end(),' '), s.end());
		int n=0,sign=1;
		if(s[0]=='-')
		{
		    sign=-1;
		    for(int i=1;i<s.size();i++)
		    {
		        if(!isdigit(s[i]))
		        {
		            return n*sign;
		        }
		        if(n*sign<=INT_MIN)
		            return sign*INT_MIN;
		        n=n*10+(s[i]-'0');

		    }
		}
		else
		{
		    for(int i=0;i<s.size();i++)
		    {
		        if(!isdigit(s[i]))
		        {
		            return n*sign;
		        }
		        if(n*sign>=INT_MAX)
		            return sign*INT_MAX;
		        n=n*10+(s[i]-'0');
		    }
		}
		return n*sign;*/
	}
};