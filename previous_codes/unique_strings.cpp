#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Use the trie data structure to store the string.

class Solution {
public:
	struct node
	{
		struct node * link[26];
		node()
		{
			for (int i = 0; i < 26; i++)
				link[i] = NULL;
		}
	};
	void insert(struct node *cur, int pos, string &s)
	{
		if (pos == s.size())
		{
			return;
		}
		if (cur->link[s[pos] - 'a'] == NULL)
		{
			cur->link[s[pos] - 'a'] = new node();
		}
		insert(cur->link[s[pos] - 'a'], pos + 1, s);
	}
	void dfs(struct node *cur, vector<string> &answer, string &tmp)
	{
		int leaf = 1;
		for (int i = 0; i < 26; i++)
		{
			if (cur->link[i] == NULL)
				continue;
			leaf = 0;
			tmp.push_back(char(i + 'a'));
			dfs(cur->link[i], answer, tmp);
			tmp.pop_back();
		}
		if (leaf)
		{
			if (tmp.size())
				answer.push_back(tmp);
			return ;
		}
	}
	vector<string> solve(int N, vector<string> arr) {
		//code here
		node *root = new node();
		vector<string> answer;
		for (auto i : arr)
		{
			insert(root, 0, i);
		}
		string tmp = "";
		dfs(root, answer, tmp);
		return answer;
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
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (auto i : a)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}