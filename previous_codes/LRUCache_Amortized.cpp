#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class LRU {
public:
	list <pair<int, int>> q;
	unordered_map<int, list<pair<int, int>>::iterator>m;
	int size;
	LRU(int x)
	{
		size = x;
		m.clear();
		q.clear();
	}
	void set(int key, int value)
	{
		if (m.find(key) == m.end())
		{
			if (q.size() == size)
			{
				int l_key = q.back().first;
				int l_value = q.back().second;
				q.pop_back();
				m.erase(l_key);
			}
		}
		else
			q.erase(m[key]);
		q.push_front({key, value});
		m[key] = q.begin();
	}

	int get(int key)
	{
		if (m.find(key) == m.end())
			return -1;
		else
		{
			auto i = m.find(key);
			int value = (*(i->second)).second;
			q.erase(i->second);
			q.push_front({key, value});
			m[key] = q.begin();
			return value;
		}
	}

};



int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	LRU l(n);
	while (q--)
	{
		int c;
		cin >> c;
		if (c == 1)
		{
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
		else if (c == 2)
		{
			int key;
			cin >> key;
			cout << l.get(key) << " ";
		}
	}
	cout << endl;


	return 0;
}