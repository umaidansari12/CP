#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class MyDS {
private:
	vector<int> arr;
	unordered_map<int, int> Map;
	// map can perform first three operations in constant time and we use resizable array to get the elements in random order
public:
	void add(int x) {
		// checking if the element is already present in the map if present then return otherwise add in map with the last index and at the end of the array
		if (Map.find(x) != Map.end())
			return;
		int index = arr.size() - 1;
		Map.insert({x, index});
		arr.push_back(x);
	}
	void remove(int x) {
		//checking if the element is already present in the map or not if present then we remove it by taking the index of the element and removing it from the map then swapping the array last index with the index of the element as it is O(1) to remove the last element from the array
		if (Map.find(x) == Map.end())
			return;
		int index = Map[x];
		Map.erase(x);
		int last = arr.size() - 1;
		swap(arr[index], arr[last]);
		arr.pop_back();
	}
	int search(int x) {
		if (Map.find(x) != Map.end())
			return Map[x];
		return -1;
	}
	int getRandom() {
		srand(time(NULL));

		int index = rand() % arr.size();
		return arr[index];

	}

};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	MyDS ds;
	ds.add(10);
	ds.add(20);
	ds.add(30);
	ds.add(40);
	cout << ds.search(30) << endl;
	ds.remove(20);
	ds.add(50);
	cout << ds.search(50) << endl;
	cout << ds.getRandom() << endl;


	return 0;
}