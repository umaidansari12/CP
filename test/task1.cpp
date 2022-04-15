#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int task(string s) {
	int max_blocks = 1, _size = s.size(), block_size = 1, ans = 0;

	for (int i = 1; i < _size; i++) {
		if (s[i] == s[i - 1]) {
			block_size++;
		}
		else {
			max_blocks = max(max_blocks, block_size);
			block_size = 1;
		}
	}
	max_blocks = max(max_blocks, block_size);
	block_size = 1;
	for (int i = 0; i < _size - 1; i++) {
		if (s[i] == s[i + 1]) {
			block_size++;
		}
		else {
			ans += (max_blocks - block_size);
			block_size = 1;
		}
	}

	ans += (max_blocks - block_size);


	return ans;
}


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << task(s) << endl;
	}
}