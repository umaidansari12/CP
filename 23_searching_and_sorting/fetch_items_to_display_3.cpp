#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Item {
public:
	string name;
	int relevance, price, sortParameter, sortOrder;
	Item() {

	}
	Item(string name, int relevance, int price, int sortParameter, int sortOrder) {
		this->name = name;
		this->relevance = relevance;
		this->price = price;
		this->sortParameter = sortParameter;
		this->sortOrder = sortOrder;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int numberOfItems, sortParameter, sortOrder, itemsPerPage, pageNumber;
		cin >> numberOfItems >> sortParameter >> sortOrder >> itemsPerPage >> pageNumber;

		vector<Item> items(numberOfItems);
		for (int i = 0; i < numberOfItems; i++) {
			// Item item;
			// cin >> item.name;
			// cin >> item.relevance;
			// cin >> item.price;
			// item.sortParameter = sortParameter;
			// item.sortOrder = sortOrder;
			// items.push_back(item);
			cin >> items[i].name;
			cin >> items[i].relevance;
			cin >> items[i].price;
			items[i].sortOrder = sortOrder;
			items[i].sortParameter = sortParameter;
		}

		sort(items.begin(), items.end(), [](Item a, Item b) {
			if (a.sortOrder == 0) {

				if (a.sortParameter == 0) {
					return a.name < b.name;
				}
				else if (a.sortParameter == 1) {
					return a.relevance < b.relevance;
				}
				else if (a.sortParameter == 2) {
					return a.price < b.price;
				}

			}
			else if (a.sortOrder == 1) {
				if (a.sortParameter == 0) {
					return a.name > b.name;
				}
				else if (a.sortParameter == 1) {
					return a.relevance > b.relevance;
				}
				else if (a.sortParameter == 2) {
					return a.price > b.price;
				}
			}

			return false;
		});

		for (int i = 0; i < numberOfItems; i++) {
			cout << items[i].name << " " << items[i].relevance << " " << items[i].price << endl;
		}


	}

	return 0;
}