#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> maxInWindow(vector<int> input, int k) {
	vector<int> output;
	int i = 0;
	deque<int> q(k);
	for (i = 0; i < k; i++)
	{
		while (!q.empty() && input[q.back()] <= input[i])
			q.pop_back();
		q.push_back(i);
	}
	for (; i < input.size(); i++)
	{
		output.push_back(input[q.front()]);
		while (!q.empty() && q.front() <= (i - k))
			q.pop_front();
		while (!q.empty() && input[q.back()] <= input[i])
			q.pop_back();
		q.push_back(i);
	}
	output.push_back(input[q.front()]);
	return output;
}

vector<int> maxInWindowBrute(vector<int> input, int k) {
	vector<int> output;
	for (int i = 0; i <= input.size() - k; i++)
	{
		int m = 0;
		for (int j = i; j < i + k; j++)
		{
			m = max(m, input[j]);
		}
		output.push_back(m);
	}
	return output;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> r = maxInWindow(a, k);
		for (auto i : r)
			cout << i << " ";
		cout << endl;

	}


	return 0;
}