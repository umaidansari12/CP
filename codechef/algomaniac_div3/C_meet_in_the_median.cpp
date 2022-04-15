#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(int idx, int &median, vector<int> &a, int n, int k, vector<int> &r, vector<int>&res)
{
	if (idx > n or r.size() > k)
		return;
	if (idx == n and r.size() == k)
	{
		vector<int> temp(r);
		sort(temp.begin(), temp.end());
		if (median < temp[(k / 2)])
		{
			res = r;
			median = temp[(k / 2)];
			return;
		}
	}
	r.push_back(a[idx]);
	solve(idx + 1, median, a, n, k, r, res);
	r.pop_back();
	solve(idx + 1, median, a, n, k, r, res);
}

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// int T; cin >> T;
	// while (T--) {
	// 	int N, K; cin >> N >> K;

	// 	vector < pair <int, int>> A(N);
	// 	for (int x = 0; x < N; x++) {
	// 		int i; cin >> i;
	// 		A[x] = {i, x};
	// 	}
	// 	sort(A.begin(), A.end());

	// 	vector<pair<int, int>> B(A.end() - K, A.end());

	// 	cout << B[(K + 1) / 2 - 1].first << "\n";

	// 	sort(B.begin(), B.end(), [](auto p, auto q) {
	// 		return p.second < q.second;
	// 	});

	// 	for (auto &i : B) cout << i.first << " ";
	// 	cout << "\n";
	// }

	int t;
	cin >> t;
	while (t--) {
		int n, k, median = 0;
		cin >> n >> k;
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back({x, i});
		}
		sort(a.begin(), a.end());
		vector<pair<int, int>> b(a.end() - k, a.end());
		cout << b[(k + 1) / 2 - 1].first << "\n";
		sort(b.begin(), b.end(), comp);
		for (auto i : b)
			cout << i.first << " ";
		cout << endl;
		// vector<int> res;
		// vector<int> r;
		// solve(0, median, a, n, k, r, res);
		// cout << median << endl;
		// for (auto i : res)
		// 	cout << i << " ";
		// cout << endl;
	}


	return 0;
}

