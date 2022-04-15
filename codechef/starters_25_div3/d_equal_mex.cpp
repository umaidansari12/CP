#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mex(vector<int> v, int start, int end) {
	int count[end + 1] = {0};
	for (int i = start; i < end; i++) {
		count[v[i]]++;
	}
	for (int i = 0; i <= end; i++) {
		if (count[i] == 0)
			return i;
	}
	return 0;
}

bool solve(vector<int> &v, map<int, int> &count, int n) {

	for (auto i : count) {
		if (i.second == 0)
			return "YES";
	}
	return "NO";

}

bool solve1(vector<int> &v, map<int, int> &count, int n) {
	//cout << endl;
	int a = mex(v, 0, n / 2);
	int b = mex(v, n / 2, n);
	//cout << a << " ";
	//cout << b << '\n';
	if (a == b) {
		cout << "YES\n";
	}
	else {
		bool f = true;
		for (auto i : count) {
			if (i.second % 2 == 1) {
				f = false;
				cout << "NO\n";
				break;
			}
		}
		if (f)
			cout << "YES\n";
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n *= 2;
		//cout << n << endl;
		vector<int> v(n);
		map<int, int> count;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			count[v[i]]++;
			//cout << v[i] << " ";
		}

		cout << solve(v, count, n) << endl;



	}


	return 0;
}