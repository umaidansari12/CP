#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countPairsWithGivenSumSorting(int a[], int n, int k) {
	sort(a, a + n);
	int i = 0, j = n - 1, count = 0;
	while (i < j) {
		int sum = a[i] + a[j];
		if (sum == k) {
			count += 1;
			while (i < j and a[i] == a[i + 1])
				i++;
			while (i < j and a[j] == a[j - 1])
				j--;
			i++;
			j--;
		}
		else if (sum < k)
			i++;
		else
			j--;
	}
	return count;
}

int countPairsWithGivenSum(int a[], int n, int k) {
	int count = 0;
	unordered_map<int, int> freq;
	for (int i = 0; i < n; i++) {
		// freq[a[i]]++;
		// if (freq.find(k - a[i]) != freq.end()) {
		// 	count++;
		// }
		freq[a[i]]++;
	}
	for (auto i : freq) {
		if ((2 * i.first) == k) {
			if (freq[i.first] > 1)
				count += 2;
		}
		else {
			if (freq[k - i.first])
				count++;
		}
	}
	return count / 2;
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
		int a[n] = {0};
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << countPairsWithGivenSum(a, n, k) << endl;
	}


	return 0;
}