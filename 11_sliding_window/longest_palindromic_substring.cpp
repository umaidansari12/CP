#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.size() - 1;
		while (left <= right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	string longestPalindrome(string s) {
		int _size = s.size(), _max = 0;
		string ans = "";
		for (int i = 0; i < _size; i++) {
			string temp = "";
			for (int j = i; j < _size; j++) {
				temp += s[j];
				if (isPalindrome(temp) and (_max < (j - i + 1))) {
					ans = temp;
					_max = j - i + 1;
				}
			}
		}
		return ans;
	}
};

class Solution_Optimal {
public:
	string expand(string &s, int l, int h) {
		int _size = s.size();
		while (l >= 0 and h < _size and s[l] == s[h]) {
			l--;
			h++;
		}
		return s.substr(l + 1, h - l - 1);
	}
	string longestPalindrome(string s) {
		if (s.size() <= 1)
			return s;
		string answer = s.substr(0, 1);
		int _size = s.size();
		for (int i = 0; i < _size; i++) {
			string odd = expand(s, i, i);
			string even = expand(s, i, i + 1);
			if (answer.size() < odd.size()) {
				answer = odd;
			}
			if (answer.size() < even.size()) {
				answer = even;
			}
		}
		return answer;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		// Solution ob = Solution();
		Solution_Optimal ob = Solution_Optimal();
		cout << ob.longestPalindrome(s) << endl;
	}
}
