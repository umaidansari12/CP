#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> arr, int i) {
	int x = arr[i];
	if (i == 0) {
		return x > arr[1];
	}
	if (i == arr.size() - 1) {
		return x < arr[i - 1];
	}
	return x > arr[i + 1] or x < arr[i - 1];

}

pair<int, int> subarraySort(vector<int> arr) {

	int smallest = INT_MAX;
	int largest = INT_MIN;

	for (int i = 0; i < arr.size(); i++) {
		int x = arr[i];

		if (outOfOrder(arr, i)) {
			smallest = min(smallest, x);
			largest = max(largest, x);
		}
	}

	//next step find the right index where smallest and largest lie (subarray) for out solution
	if (smallest == INT_MAX) {
		return { -1, -1};
	}

	int left = 0;
	while (smallest >= arr[left]) {
		left++;
	}
	int right = arr.size() - 1;
	while (largest <= arr[right]) {
		right--;
	}

	return {left, right};

}


pair<int, int> subarraySorting(vector<int> a) {
	//Expected Optimal Complexity O(n) Time, O(1) Space
	//may be start with O(NLogN) and try to improve
	//complete this function
	vector<int> b(a);
	sort(b.begin(), b.end());
	int start = INT_MAX, end = INT_MIN;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			start = min(start, i);
			end = max(end, i);
		}
	}


	if (start == INT_MAX)
		return make_pair(-1, -1);
	return make_pair(start, end);

}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
	auto p = subarraySort(arr);
	cout << p.first << " and " << p.second << endl;

	return 0;
}