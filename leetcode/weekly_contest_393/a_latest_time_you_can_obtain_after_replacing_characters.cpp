
class Solution {
public:
	string findLatestTime(string s) {
		if (s[0] == '?') {
			if ((s[1] - '0') > 1 and (s[1] - '0') <= 9)
				s[0] = '0';
			else
				s[0] = '1';
		}
		if (s[1] == '?') {
			if ((s[0] - '0') == 0)
				s[1] = '9';
			else
				s[1] = '1';
		}
		if (s[3] == '?') {
			s[3] = '5';
		}
		if (s[4] == '?')
			s[4] = '9';
		return s;
	}
};