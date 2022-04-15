#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void permute(string s, int l, int r, vector<string>&re)
{
	if (l == r)
	{
		re.push_back(s);
		return;
	}
	for (int j = l; j <= r; j++)
	{
		swap(s[l], s[j]);
		permute(s, l + 1, r, re);
		swap(s[l], s[j]);
	}
}

/**
 * 1. a max number has the property of decreasing in every digit: 9876
 * 2. find the first non-max substring from the right; ex. in 1234(59876), 59876 is the first non-max substring from the right
 * 3. sort the max part of 5(9876), by reverse, becames 5(6789);
 * 4. flip 5,6, becames 65789; because 6 is the next smallest digit than 5, in 56789;
 * 5. incase of 66789, you got flip 6 with 7 to make it 76689, to make it bigger.
 */
class Solution {
public:
	int nextGreaterElement(int n) {
		string s = to_string(n);
		if (s.length() == 1) {
			return -1;
		}
		/* find the first decreasing digit from the right, eg: 59876, 5 is the first decreasing digit */
		int i = s.length() - 2; // 21 -> i = 0; 59876 -> i = 3
		for (; i >= 0 && s[i] >= s[i + 1]; i--) { }
		if (i == -1) {  // if a decreasing digit cannot be find, the number cannot be larger.
			return -1;
		}
		reverse(s.begin() + i + 1, s.end());
		for (int j = i + 1; j < s.length(); j++) {
			if (s[j] > s[i]) {
				swap(s[i], s[j]);
				break;
			}
		}
		long next = stol(s);
		return next == n || next > INT_MAX ? -1 : next;
	}
};
class Solution {
public:

	int nextGreaterElement(int n) {
		int t = n;
		string s;
		vector<int> nu;
		while (t > 0)
		{
			nu.push_back(t % 10);
			t /= 10;
		}
		reverse(nu.begin(), nu.end());
		int ind1 = nu.size() - 2;
		while (ind1 > 0 && nu[ind1] > nu[ind1 + 1])
		{
			ind1--;
		}
		if (ind1 < 0)
		{
			reverse(nu.begin(), nu.end());
		}
		int ind2 = nu.size() - 1;
		while (ind2 > ind1 && nu[ind2] < nu[ind1])
			ind2--;
		swap(nu[ind1], nu[ind2]);
		reverse(nu.begin() + ind1 + 1, nu.end());

		for (int i = 0; i < nu.size(); i++)
			s = s + to_string(nu[i]);
		int n1 = stoi(s);
		return n1 > n ? n1 : -1;
	}
};

class Solution {
public:

	int nextGreaterElement(int n) {
		string s = to_string(n);
		next_permutation(s.begin(), s.end());
		int n1 = stoll(s);
		return (n1 <= n || n1 > INT_MAX) ? -1 : n1;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	/*cin.tie(NULL);
	cout.tie(NULL);*/
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s = to_string(n);
		/*//cout << s << endl;
		reverse(s.begin(), s.end());
		//cout << s << endl;
		int n1 = stoi(s);
		cout << n1 << endl;
		if (n1 > n && n1 <= INT_MAX)
			cout << n1 << endl;
		else
			cout << -1 << endl;*/
		vector<string> res;
		permute(s, 0, s.size() - 1, res);
		sort(res.begin(), res.end());
		int idx = lower_bound(res.begin(), res.end(), s) - res.begin();
		int num = stoi(res[idx]);
		if (idx + 1 == res.size())
			cout << -1 << endl;
		else if ( num >= INT_MAX)
			cout << -1 << endl;
		else
		{
			for (int i = idx; i < res.size(); i++)
				if (res[i] != res[idx])
				{
					cout << res[i] << endl;
					break;
				}
		}



	}


	return 0;
}