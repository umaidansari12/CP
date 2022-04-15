#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> m;
		deque<int> q(k);
		int i;
		for (i = 0; i < k; i++)
		{
			while (!q.empty() && nums.at(i) >= nums.at(q.back()))
			{
				q.pop_back();
			}
			q.push_back(i);
		}
		int n = nums.size();
		for (; i < n; i++)
		{
			m.push_back(nums.at(q.front()));
			while (!q.empty() && q.front() <= i - k)
			{
				q.pop_front();
			}
			while (!q.empty() && nums.at(i) >= nums.at(q.back()))
			{
				q.pop_back();
			}
			q.push_back(i);
		}
		m.push_back(nums.at(q.front()));
		return m;
	}
};

void maxSubarraySliding(vector<int> &a, int n, int k)
{
	deque<int> q(k);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		while (!q.empty() && a[i] >= a[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	for (; i < n; i++)
	{
		cout << a[q.front()] << " ";
		while (!q.empty() && q.front() <= (i - k))
		{
			q.pop_front();
		}
		while (!q.empty() && a[i] >= a[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	cout << a[q.front()] << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		/*for (int i = 0; i <= n - k; i++)
		{
			int ma = a[i];
			for (int j = i; j < i + k; j++)
			{
				ma = max(ma, a[j]);
			}
			cout << ma << " ";
		}*/
		maxSubarraySliding(a, n, k);
		cout << endl;
	}


	return 0;
}