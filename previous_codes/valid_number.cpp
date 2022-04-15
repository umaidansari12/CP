class Solution {
public:
	bool isNumber(string s) {
		bool digitseen = false, eseen = false, dotseen = false;
		int countPlusMinus = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (isdigit(s[i]))
			{
				digitseen = true;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (countPlusMinus == 2)
					return false;
				if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E'))
					return false;

				if (i == s.size() - 1)
					return false;
				countPlusMinus++;
			}
			else if (s[i] == '.')
			{
				if (eseen || dotseen)
					return false;
				if (i == s.size() - 1 && !digitseen)
					return false;
				dotseen = true;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				if (eseen || !digitseen || i == s.size() - 1)
					return false;
				eseen = true;
			}
			else
				return false;
		}
		return true;

	}
};

int Solution::isNumber(const string A) {
	int i = 0;
	int n = A.length();
	while (A[i] == ' ') { ++i; }
	if (i == n)
		return 0;

	if ((A[i] == '-' || A[i] == '+') && ((A[i + 1] >= '0' && A[i + 1] <= '9') || A[i + 1] == '.'))
		i += 2;
	else if (A[i] == 'e')
		return 0;

	bool eflag = false, dflag = false;

	while (i < n)
	{
		if (A[i] == '.')
		{
			if (eflag || dflag)
				return 0;
			else if (A[i + 1] >= '0' && A[i + 1] <= '9')
				i += 2;
			else
				return 0;
			dflag = true;
		}
		else if (A[i] == 'e')
		{
			if (eflag)
				return 0;
			eflag = true;
			if ((A[i + 1] == '-' || A[i + 1] == '+') && (A[i + 2] >= '0' && A[i + 2] <= '9'))
				i += 3;
			else if (A[i + 1] >= '0' && A[i + 1] <= '9')
				i += 2;
			else
				return 0;
		}
		else if (A[i] >= '0' && A[i] <= '9')
			++i;
		else if (A[i] == ' ')
		{
			++i;
			while (A[i] == ' ') { ++i; }
			if (i == n)
				return 1;
		}
		else
			return 0;
	}
	return 1;
}

