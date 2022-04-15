#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Queue {
public:
	stack<int> s1;
	stack<int> s2;
	void enqueue(int x)
	{
		s1.push(x);
	}
	int dequeue()
	{
		int x;
		if (s1.empty() && s2.empty()) return -1;
		if (!s2.empty())
		{
			x = s2.top();
			s2.pop();
		}
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			x = s2.top();
			s2.pop();
		}
		return x;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int qc;
		cin >> qc;
		while (qc--)
		{
			Queue q;
			int n;
			cin >> n;
			if (n == 1)
			{
				int x;
				cin >> x;
				q.enqueue(x);
			}
			else if (n == 2)
			{
				cout << q.dequeue() << " ";
			}
		}

	}


	return 0;
}