#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void findMedian(vector<int> a, int n)
{
	priority_queue<int> max_heap;
	priority_queue<int, vector<int> , greater<int>> min_heap;
	max_heap.push(a[0]);
	float med = a[0];
	cout << med << " ";
	for (int i = 1; i < n; i++)
	{
		if (max_heap.size() > min_heap.size())
		{
			if (a[i] < med)
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(a[i]);
			}
			else
			{
				min_heap.push(a[i]);
			}
			med = (max_heap.top() + min_heap.top()) / 2.0;
		}
		else if (max_heap.size() == min_heap.size())
		{
			if (a[i] < med)
			{
				max_heap.push(a[i]);
				med = max_heap.top();
			}
			else
			{
				min_heap.push(a[i]);
				med = min_heap.top();
			}
		}
		else
		{
			if (a[i] < med)
			{
				max_heap.push(a[i]);
			}
			else
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(a[i]);
			}
			med = (max_heap.top() + min_heap.top()) / 2.0;
		}
		cout << med << " ";
	}



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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		findMedian(a, n);
	}


	return 0;
}