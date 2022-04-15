#include <bits/stdc++.h>

using namespace std;
using ll = long long;



void push(vector<stack<int>>& stacks, int value, int& capacity)
{
	//cout<<"hello\n";
	if (stacks.size() == 0)
	{
		stack<int> s;
		s.push(value);
		stacks.push_back(s);
		return;
	}
	stack<int> s = stacks[stacks.size() - 1];
	if (s.size() == capacity)
	{
		stack<int> s1;
		s1.push(value);
		stacks.push_back(s1);
	}
	else
	{
		stacks[stacks.size() - 1].push(value);
	}

}

void pop(vector<stack<int>>& stacks, int& capacity)
{
	stack<int> s = stacks[stacks.size() - 1];
	if (s.size() == 0)
	{
		stacks.pop_back();
		stacks[stacks.size() - 1].pop();
	}
	else
	{
		stacks[stacks.size() - 1].pop();
	}
}

void display(vector<stack<int>>& stacks)
{
	//cout << "hello\n";
	for (int i = 0; i < stacks.size(); i++)
	{
		stack<int> s = stacks[i];
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<stack<int>> stacks;
	int operations, x, capacity;
	cin >> capacity >> operations;

	for (int i = 0; i < operations; i++)
	{
		//cout << i << endl;
		//cin.ignore();
		cin >> x;
		if (x == 1)
		{
			int v;
			//cin.ignore();
			cin >> v;
			push(stacks, v, capacity);
		}
		else if (x == 2)
		{
			pop(stacks, capacity);
		}
	}
	display(stacks);


	return 0;
}
