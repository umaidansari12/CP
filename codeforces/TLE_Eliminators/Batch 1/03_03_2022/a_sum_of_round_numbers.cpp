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
	while (t--) {
		int n, faceValue = 1, rem;
		cin >> n;
		vector<int> res;
		while (n) {
			rem = n % 10;
			if (rem > 0) {
				res.push_back(faceValue * rem);
			}
			n /= 10;
			faceValue *= 10;
		}
		cout << res.size() << endl;
		for (auto i : res) {
			cout << i << " ";
		}
		cout << endl;
	}


	return 0;
}