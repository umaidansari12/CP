#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class getMinMax {
	list<int> ls;
public:

	int findMin() {
		return ls.front();
	}
	int findMax() {
		return ls.back();
	}
	void deleteMin() {
		if (ls.size() == 0)
			return;
		cout << ls.front() << "Deleted\n";
		ls.pop_front();
	}
	void deleteMax() {
		if (ls.size() == 0)
			return;
		cout << ls.back() << "Deleted\n";
		ls.pop_back();
	}

	void display() {
		list<int> :: iterator it = ls.begin();
		for (it = ls.begin(); it != ls.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	void insert(int x) {
		ls.push_back(x);
		list<int>:: iterator it = ls.begin();
		for (it = ls.begin(); it != prev(ls.end()); it++) {
			list<int> ::iterator it1 = next(it, 1);
			if (x > *(it) and x < * (it1)) {
				swap(*(ls.end()), *(it1));
				break;
			}
		}
		swap(*(ls.end()), *(ls.begin()));
		display();
	}


};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getMinMax ob;
	ob.insert(50);
	ob.insert(20);
	ob.insert(30);
	// int t;
	// cin >> t;
	// while (t--) {

	// }


	return 0;
}