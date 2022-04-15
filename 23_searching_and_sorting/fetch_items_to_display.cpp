#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Amazon website contains one to many items in each pagee. To mimic the logic of the websire, an Amazon programmer has a list of items and each item has its name, relevance and price. After sorting the items by [name:0, relevance:1, price:2], the programmer is trying to find out a list of items displayed in a chosen page.

Given a list of items, the sort column, the sortd order(0: ascending, 1:descending), the number of utems to be displayed in each page and a page number, write an algorithm to determine the list of item names in the specified page while respecting the item's order. Page Number starts from 0.
Sample Input:
numOfItems = 3
items: ["item1",10,15],["item2",3,4],["item3",17,8]
sortParameter: 1
sortOrder: 0
itemsPerPage: 2
pageNumber: 1
Output:
{"item3"}
*/

vector<string> fetchItemsToDisplay(int numOfItems, map<string, pair<int, int>> items, int sortParameter, int sortOrder, int itemsPerPage, int pageNumber) {
	return {};
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int numOfItems;
		cin >> numOfItems;
		map<string, pair<int, int>> items;
		for (int i = 0; i < numOfItems; i++) {
			string item;
			int relevance, price;
			cin >> item;
			cin >> relevance >> price;

			items.insert({item, {relevance, price}});

		}
		for (auto item : items) {
			cout << item.first << " " << item.second.first << " " << item.second.second << endl;
			res
		}
		int sortParameter;
		cin >> sortParameter;
		int sortOrder;
		cin >> sortOrder;
		int itemsPerPage;
		cin >> itemsPerPage;
		int pageNumber;
		cin >> pageNumber;
		if (sortParameter == 0) {
			if (sortOrder == 0) {
				sort(items.begin(), items.end(), [](pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
					return a.first < b.first;
				});

			}
			else if (sortOrder == 1) {
				sort(items.begin(), items.end(), [](pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
					return a.first > b.first;
				});
			}
		}
		else if (sortParameter == 1) {
			if (sortOrder == 0) {
				sort(items.begin(), items.end(), [](pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
					return a.second.first < b.second.first;
				});

			}
			else if (sortOrder == 1) {
				sort(items.begin(), items.end(), [](pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
					return a.second.first > b.second.first;
				});
			}

		}
		else if (sortParameter == 2) {
			if (sortOrder == 0) {
				sort(items.begin(), items.end(), [](pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
					return a.second.second < b.second.second;
				});

			}
			else if (sortOrder == 1) {
				sort(items.begin(), items.end(), [](pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
					return a.second.second > b.second.second;
				});
			}
		}
		for (auto item : items) {
			cout << item.first << " " << item.second.first << " " << item.second.second << endl;
		}

	}


	return 0;
}