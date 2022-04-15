#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int cntSubarrays(vector<int> arr, int k) {
	//complete this method
	int ans = 0, sum = 0;
	unordered_map<int, int> cnt;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
		if (sum == k)
			ans++;
		if (cnt.find(sum - k) != cnt.end())
			ans += cnt[sum - k];
		cnt[sum]++;
	}

	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << cntSubarrays(a, k) << endl;
	}



	return 0;
}