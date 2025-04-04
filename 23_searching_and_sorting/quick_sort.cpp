#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	//Function to sort an array using quick sort algorithm.
	void quickSort(int arr[], int low, int high)
	{
		// code here
		if (low < high) {
			int partition_index = partition(arr, low, high);
			quickSort(arr, low, partition_index - 1);
			quickSort(arr, partition_index + 1, high);
		}
	}

public:
	int partition (int arr[], int low, int high)
	{
		// Your code here
		int pivot = arr[low];
		int i = low, j = high;
		while (i < j) {
			while (arr[i] <= pivot and i <= high - 1) {
				i++;
			}
			while (arr[j] > pivot and j >= low + 1) {
				j--;
			}
			if (i < j) {
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[low], arr[j]);
		return j;

	}
};

int partition(vector<int> &arr, int low, int high) {
	int pivot = low;
	int i = low;
	int j = high;
	while (i < j) {
		while (arr[i] <= arr[pivot] and i <= high) {
			i++;
		}
		while (arr[j] > arr[pivot] and j >= low) {
			j--;
		}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[pivot], arr[j]);
	return j;
}

void quick_sort_helper(vector<int> &arr, int low, int high) {
	if (low < high) {
		int partition_index = partition(arr, low, high);
		quick_sort_helper(arr, low, partition_index - 1);
		quick_sort_helper(arr, partition_index + 1, high);
	}
}
vector<int> quickSort(vector<int> arr)
{
	// Write your code here.
	int _size = arr.size();
	quick_sort_helper(arr, 0, _size - 1);
	return arr;
}


// 1. Pick a pivot and place in its correct place in the sorted array, and tell what is the partition index
// pivot can be
// a. 1st element in the array
// b. last element in the array
// c. median of the array
// d. random element of the array
// 2. smaller on the left and larger on the right
// 1. Find the element
// Time Complexity - O(NlogN)
// Space Complexity - O(1)

int main() {
	int T;
	cin >> T;

	while (T--) {
	}
}