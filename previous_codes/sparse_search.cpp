#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int sparseSearch(vector<string>&a, int l, int h, string s)
{
	while (l <= h)
	{
		int m = (l + h) / 2;
		int mid_left = m - 1;
		int mid_right = m + 1;
		if (a[m] == "")
		{
			while (true)
			{
				if (mid_left<l and mid_right>h)
					return -1;
				else if (mid_right <= h and a[mid_right] != "")
				{
					m = mid_right;
					break;
				}
				else if (mid_left >= l and a[mid_left] != "")
				{
					m = mid_left;
					break;
				}
				mid_left--;
				mid_right++;
			}
		}
		if (a[m] == s)
		{
			return m;
		}
		else if (a[m] > s)
			h = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
int main()
{

	vector<string> a = {"for", "geeks", "", "", "", "", "ide",
	                    "practice", "", "", "", "quiz"
	                   };
	string s;
	cin >> s;
	cout << sparseSearch(a, 0, 11, s) << endl;

	return 0;
}