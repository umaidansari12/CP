#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void nextGreaterFrequencyElementBrute(int a[], int n) {
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		bool f = false;
		for (int j = i + 1; j < n; j++) {
			if (m[a[j]] > m[a[i]])
			{
				f = true;
				cout << a[j] << " ";
				break;
			}
		}
		if (!f)
			cout << -1 << " ";
	}
	cout << endl;
}

void nextGreaterFrequencyElement(int arr[], int n) {
	unordered_map<int, int> freq;
	stack<pair<int, int>> myStack;//pair<element,frequency>
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	int curr_freq = freq[arr[n - 1]];
	int res[n] = {0};
	res[n - 1] = -1;
	myStack.push({arr[n - 1], curr_freq});
	for (int i = n - 2; i >= 0; i--) {
		curr_freq = freq[arr[i]];
		while (!myStack.empty() and curr_freq >= myStack.top().second) {
			myStack.pop();
		}
		res[i] = (myStack.empty()) ? -1 : myStack.top().first;
		myStack.push({arr[i], freq[arr[i]]});
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

void nextGreaterFrequencyElementAnother(int arr[], int n) {
	unordered_map<int, int> freq;
	stack<int> s;//pair<element,frequency>
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	s.push(0);
	for (int i = 1; i < n; i++) {
		if (freq[arr[i]] >= freq[arr[s.top()]]) {
			s.push(i);
		}
		else
		{
			while (!s.empty() and freq[arr[s.top()]] < freq[arr[i]])
			{
				res[s.top()] = arr[i];
				s.pop();
			}
			s.push(i);
		}
	}
	while (!s.empty()) {
		res[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
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
		nextGreaterFrequencyElementAnother(a, n);
	}


	return 0;
}