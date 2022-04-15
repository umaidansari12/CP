#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int CountBuildings(int arr[], int n) {
	int count = 0, prevMax = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (prevMax < arr[i])
			count++;
		prevMax = max(prevMax, arr[i]);
	}
	return count;
}

int Rearrange(int n) {
	int temp = n;
	vector<int> arr;
	while (temp) {
		arr.push_back(temp % 10);
		temp /= 10;
	}
	reverse(arr.begin(), arr.end());
	temp = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (i % 2 == 0) {
			temp = temp * 10 + arr[i];
		}
	}

	return temp;
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
		// int a[n] = {0};
		// for (int i = 0; i < n; i++) {
		// 	cin >> a[i];
		// }
		//cout << CountBuildings(a, n) << endl;
		cout << Rearrange(n) << endl;

	}

	return 0;
}