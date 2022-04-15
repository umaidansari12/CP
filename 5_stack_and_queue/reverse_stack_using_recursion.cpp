#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*The idea of the solution is to hold all values in Function Call Stack until
  the stack becomes empty. When the stack becomes empty, insert all held
  items one by one at the bottom of the stack. */

void insert_at_bottom(stack<int> &s, int x)
{
	if (s.size() == 0)
	{
		s.push(x);
	}
	else
	{
		// All items are held in Function Call
		// Stack until we reach end of the stack
		// When the stack becomes empty, the
		// st.size() becomes 0, the above if
		// part is executed and the item is
		// inserted at the bottom
		int a = s.top();
		s.pop();
		insert_at_bottom(s, x);
		// push allthe items held in
		// Function Call Stack
		// once the item is inserted
		// at the bottom
		s.push(a);
	}
}


void reverse(stack<int> &s)
{
	if (s.size() == 0)
		return;
	else
	{
		// Hold all items in Function
		// Call Stack until we
		// reach end of the stack
		int x = s.top();
		s.pop();
		reverse(s);
		// Insert all the items held
		// in Function Call Stack
		// one by one from the bottom
		// to top. Every item is
		// inserted at the bottom
		insert_at_bottom(s, x);
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
		int n, x;
		cin >> n;
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			s.push(x);
		}
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;

	}


	return 0;
}