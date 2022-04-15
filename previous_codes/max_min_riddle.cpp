#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<long long> arr(n), res;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		res.push_back(*max_element(arr.begin(), arr.end()));
		for (int k = 2; k < n ; k++)
		{
			deque<int> q;
			long long ma = INT_MIN;
			int i = 0;
			for (i = 0; i < k; i++)
			{
				while (!q.empty() && arr[i] < arr[q.back()])
					q.pop_back();
				q.push_back(i);
			}
			for (; i < n; i++)
			{
				ma = max(ma, arr[q.front()]);
				while (!q.empty() && q.front() <= i - k)
					q.pop_front();
				while (!q.empty() && arr[i] < arr[q.back()])
					q.pop_back();
				q.push_back(i);
			}
			ma = max(ma, arr[q.front()]);
			res.push_back(ma);
		}
		res.push_back(*min_element(arr.begin(), arr.end()));
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}



	return 0;
}