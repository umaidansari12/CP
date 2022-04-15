#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void nextGreaterFrequencyElementBrute(int a[], int n) {
	unordered_map<int, int> freq;
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		bool f = false;
		for (int j = i + 1; j < n; j++) {
			if (freq[a[j]] > freq[a[i]]) {
				f = true;
				res[i] = a[j];
				break;
			}
		}
		if (!f)
			res[i] = -1;
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}

void nextGreaterFrequencyElementOptimalReverse(int a[], int n) {
	unordered_map<int, int> freq;
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}
	stack<int> s;
	vector<int> res(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and freq[a[s.top()]] <= freq[a[i]])
			s.pop();
		if (!s.empty())
			res[i] = a[s.top()];
		else
			res[i] = -1;
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

void nextGreaterFrequencyElementOptimalFront(int a[], int n) {
	unordered_map<int, int> freq;
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}
	stack<int> s;
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		while (!s.empty() and freq[a[s.top()]] < freq[a[i]]) {
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		res[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
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
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		nextGreaterFrequencyElementBrute(a, n);
		nextGreaterFrequencyElementOptimalReverse(a, n);
		nextGreaterFrequencyElementOptimalFront(a, n);
	}


	return 0;
}