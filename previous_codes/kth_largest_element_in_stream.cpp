#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*1. Concept of Minheap will come into play
2. Maintain a Minheap of size K, thus heap will contrain minimum element at the top in that pile size.
Remove top element and insert and new elemenr from input array. Thus follow this procedure.*/

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		priority_queue<int, std::vector<int>, std::greater<int>> m;
		int k, n, x;
		cin >> k >> n;
		//vector<int> a(n);
		/*for (int i = 0; i < n; i++)
		{
			/*cin >> a[i];
			sort(a.begin(), a.begin() + i + 1);
			if (i < k)
				cout << "-1 ";
			else
				cout << a[k - 1] << " ";*/
		/*cin >> x;
		if (m.size() < k)
		{
			m.push(x);
			cout << "-1 ";
		}
		else if (m.size() == k ) {
			//m.pop();
			cout << m.top() << " ";
			//m.pop();
			m.push(x);


		}

		//cout << "Top " << m.top() << " " << m.size() << endl;
		}*/
		for (int i = 0; i < k - 1; i++)
		{
			cin >> x;
			m.push(x);
			cout << "-1 ";
		}
		cin >> x;
		m.push(x);
		for (int i = k; i < n; i++)
		{
			cin >> x;
			cout << m.top() << " ";
			if (x > m.top())
			{
				m.pop();
				m.push(x);
			}
		}
		cout << m.top();
		cout << endl;
	}


	return 0;
}

#include<bits/stdc++.h>
using namespace std;

class cmp
{
public:
	bool operator()(int &A, int &B)
	{
		return A > B;
	}
};

void kthLargest(int k)
{
	priority_queue<int, vector<int>, cmp> H;
	int count = 0;
	int N;
	int nn;
	cin >> nn;
	for (int i = 0; i < nn; i++)
	{

		cin >> N;
		if (H.size() < k)
			H.push(N);
		else
		{
			if (N > H.top())
			{
				H.pop();
				H.push(N);
			}



		}
		if (H.size() < k)
			cout << -1 << " ";
		else
			cout << H.top() << " ";
		count++;

	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;

		kthLargest(k);
		cout << endl;
	}
	return 0;
}


class KthLargest {
	priority_queue<int, vector<int>, greater<int>> pq;
	int size;
public:
	KthLargest(int k, vector<int>& nums) {
		size = k;
		for (int i = 0; i < nums.size(); i++)
		{
			pq.push(nums[i]);
			if (pq.size() > k)
				pq.pop();
		}

	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > size)
			pq.pop();
		return pq.top();

	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */