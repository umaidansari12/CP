#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct Node {
	int key;
	int value;
	Node *next, *pre;
	Node(int key, int value) {
		this->key = key;
		this->value = value;
		next = pre = NULL;
	}
};

/*The key to solve this problem is using a doubly linked list which enables us to quickly move nodes.
The LRU cache is a hash map of keys and double linked nodes. The hash map makes the time of get() to be O(1). The list of double linked nodes make the nodes adding/removal operations O(1).

*/

class LRUCache
{
private:
	static unordered_map<int, Node *> hsmap;
	static int capacity, count;
	static Node *head, *tail;

public:
	LRUCache(int cap)
	{
		unordered_map<int, Node *> temp;
		hsmap = temp;
		capacity = cap;
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		head->pre = NULL;
		tail->next = NULL;
		tail->pre = head;
		count = 0;
	}

	static void addToHead(Node *node)
	{
		node->next = head->next;
		node->next->pre = node;
		node->pre = head;
		head->next = node;
	}

	static void deleteNode(Node *node)
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}

	static int get(int key)
	{
		if (hsmap.count(key) > 0)
		{
			Node *node = hsmap[key];
			int result = node->value;
			deleteNode(node);
			addToHead(node);
			return result;
		}
		return -1;
	}

	static void set(int key, int value)
	{
		if (hsmap.count(key) > 0)
		{
			Node *node = hsmap[key];
			node->value = value;
			deleteNode(node);
			addToHead(node);
		}
		else
		{
			Node *node = new Node(key, value);
			hsmap[key] = node;
			if (count < capacity) {
				count++;
				addToHead(node);
			} else {
				hsmap.erase(tail->pre->key);
				deleteNode(tail->pre);
				addToHead(node);
			}
		}
	}
};

// Initializing static members
unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

class LRU {
public:
	deque <int> q;
	int size;
	unordered_map<int, deque<int>::iterator> m;
	LRU(int x)
	{
		size = x;
	}
	void set(int x, int y)
	{
		if (m.find(x) == m.end())
		{
			if (q.size() == size)
			{
				int k = q.back();
				q.pop_back();
				m.erase(k);
			}
		}
		else
		{
			q.erase(m[x]);
			m.erase(x);
		}
		q.push_front(x);
		m[x] = q.begin();
	}
	void get(int x)
	{
		if (m.find(x) != m.end())
		{
			q.erase(m[x]);
			q.push_front(x);
			cout << *m[x] << " ";
		}
		else
			cout << -1 << " ";
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
			int x, y;
			cin >> x >> y;
			l.set(x, y);
		}
		else if (c == 2)
		{
			int x;
			cin >> x;
			l.get(x);
		}
	}
	cout << endl;

	return 0;
}

// Implementation of LRU Cache using two data structures:
// 1. Doubly Linked List
// 2. HashMap

/*class LRUCache {
public:
	int cacheSize;
	map<int, int> m;
	deque<int> dq;

	LRUCache(int capacity) {
		m.clear();
		dq.clear();
		cacheSize = capacity;
	}

	int get(int key) {
		// not found
		if (m.find(key) == m.end()) {
			return -1;
		} else {
			// found
			deque<int>::iterator it = dq.begin();
			while (*it != key) {
				it++;
			}

			// update queue: update it to most recent used value
			dq.erase(it);
			dq.push_front(key);

			return m[key];
		}
	}

	void put(int key, int value) {
		// not present in cache
		if (m.find(key) == m.end()) {
			// check if cache is full
			if (cacheSize == dq.size()) {
				int last = dq.back();
				dq.pop_back();
				m.erase(last);
			}
		} else {
			// present in cache, remove it from queue and map
			deque<int>::iterator it = dq.begin();
			while (*it != key) {
				it++;
			}

			dq.erase(it);
			m.erase(key);
		}

		// update the cache
		dq.push_front(key);
		m[key] = value;
	}
};

/*class LRU_Cache {
public:
	int size;
	deque<int> q;
	map<int, int> m;
	LRUCache(int capacity) {
		size = capacity;
		m.clear();
		q.clear();
	}

	int get(int key) {
		if (m.find(key) == m.end())
			return -1;
		else
		{
			auto i = q.begin();
			for (i = q.begin(); i != q.end(); i++)
			{
				if (*i == key)
					break;
			}
			q.erase(i);
			q.push_front(key);
		}
		return m[key];
	}

	void put(int key, int value) {
		if (m.find(key) == m.end())
		{
			if (q.size() == size)
			{
				int k = q.back();
				q.pop_back();
				m.erase(k);
			}
		}
		else
		{
			auto i = q.begin();
			for (i = q.begin(); i != q.end(); i++)
			{
				if (*i == key)
					break;
			}
			q.erase(i);
			m.erase(key);
		}
		q.push_front(key);
		m[key] = value;

	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// We need to add and remove an element in O(1)
// thus we need to use linked list over an array because
// to shift the element after deletion, we need O(n) time
// with the linked list we can assign two pointers at head and tail
// and just adjust head and tail accordingly

// for checking whether the element is in the cache already or not
// we use hashtable, (unordered_map), where we store the address and the value
// this lookup becomes O(1) as well; (instead of traversal in O(n))

/*#include<bits/stdc++.h>
int _capacity;
list<int> _keys;
unordered_map<int, pair<int, list<int>::iterator>> _map;

// front denotes the recent and back denotes the least recent in this code

LRUCache::LRUCache(int capacity)
{
	_map.clear(); // need to clear the global variables
	_keys.clear(); // ________ ,, _____________________
	_capacity = capacity;
}

int LRUCache::get(int key)
{
	if (_map.find(key) != _map.end()) // if element exists in the  map
	{
		_keys.erase(_map[key].second); // remove the element
		_keys.push_front(key); // put it in front of it
		_map[key].second = _keys.begin(); // set the new node postion of that element in the map
		return _map[key].first; // return the value;
	}
	else
		return -1;
}

void LRUCache::set(int key, int value)
{
	if (_map.find(key) != _map.end())
	{
		_keys.erase(_map[key].second); // remove it
		_keys.push_front(key); // put it in the beginning
		_map[key] = {value, _keys.begin()}; // update the map for value and position
	}
	else
	{
		// check the capacity
		if (_keys.size() >= _capacity) // if exceeded
		{
			_map.erase(_keys.back()); // remove the least recent element from the map
			_keys.pop_back();              // and from the list
		}
		// insert in the beginning regardless (if capacity is full we remove and then add otherwise just add)
		_keys.push_front(key);               // insert the new key in the beginning of the list and update it
		_map[key] = {value, _keys.begin()};  // in the  map as well
	}

}*/

/*int maxSize;
list<pair<int,int>> dq;
unordered_map<int, list<pair<int,int>> :: iterator> ma;
LRUCache::LRUCache(int N)
{maxSize = N;
dq.clear();
ma.clear();
}
void LRUCache::set(int x, int y)
{
     if(ma.find(x) == ma.end())
    {
       if(dq.size() == maxSize)
       {
           int Lx = dq.back().first;
           int Ly = dq.back().second;
           dq.pop_back();
           dq.push_front({x,y});
           ma.erase(Lx);
           ma[x] =dq.begin();
       }
       else{
           dq.push_front({x,y});

            ma[x] = dq.begin();
       }
    }
    else{
        auto it = ma.find(x);
        dq.erase(it->second);
        dq.push_front({x,y});

        ma[x]=dq.begin();
    }
}
int LRUCache::get(int x)
{
    if(ma.find(x) == ma.end())
    {
        return -1;
    }
    auto it = ma.find(x);
    int d  = (*(it->second)).second;
    dq.erase(it->second);
    dq.push_front({x,d});
    ma[x] = dq.begin();
    return d;
}*/