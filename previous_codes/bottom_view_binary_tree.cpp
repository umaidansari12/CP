#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int T;
		cin >> T;
		map<int, vector<int>> m;
		while (T--)
		{
			int n, k;
			cin >> n >> k;
			while (n--)
			{
				int x;
				cin >> x;
				m[k].push_back(x);
			}
		}
		auto i = m.begin();
		while (i != m.end())
		{
			cout << i->second.back() << " ";
			i++;
		}
		cout << endl;
	}


	return 0;
}


vector <int> bottomView(Node *root)
{
	// Your Code Here
	map<int, int> m;
	queue<pair<Node*, int>> q;
	int hd = 0;
	q.push(make_pair(root, hd));
	while (!q.empty())
	{
		Node* t = q.front().first;
		hd = q.front().second;
		m[hd] = t->data;
		q.pop();
		if (t->left)
		{
			q.push(make_pair(t->left, hd - 1));
		}
		if (t->right)
		{
			q.push(make_pair(t->right, hd + 1));
		}
	}
	auto i = m.begin();
	vector<int> r;
	while (i != m.end())
	{
		r.push_back(i->second);
		i++;
	}
	return r;
}


/*void solve(Node* root, int l, map<int, vector<int>>& m)
{
	if (root == NULL)
		return;
	m[l].push_back(root->data);
	solve(root->left, l - 1, m);
	solve(root->right, l + 1, m);
}
vector <int> bottomView(Node *root)
{
	// Your Code Here
	map<int, vector<int>> m;
	solve(root, 0, m);
	auto i = m.begin();
	vector<int> r;
	while (i != m.end())
	{
		r.push_back(i->second.back());
		i++;
	}
	return r;
}
*/