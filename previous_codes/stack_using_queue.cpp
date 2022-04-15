#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Stack {
	queue<int> q1;
	queue<int> q2;
	int size;
public:
	Stack()
	{
		size = 0;
	}

	void push(int x)
	{
		size++;
		q2.push(x);
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}
	int pop()
	{
		if (q1.empty())
			return -1;
		int x = q1.front();
		q1.pop();
		size--;
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
		Stack s;
		int n;
		cin >> n;
		while (n--)
		{
			int c;
			cin >> c;
			if (c == 1)
			{
				int x;
				cin >> x;
				s.push(x);
			}
			else if (c == 2)
			{
				int r = s.pop();
				cout << r << " ";
			}
		}
		cout << endl;

	}



	return 0;
}