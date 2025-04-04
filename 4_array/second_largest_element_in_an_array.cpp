#include <bits/stdc++.h>

using namespace std;

// Brute

int print2largest(int arr[], int n) {
	sort(arr.begin(), a.end());
	int largest = arr[n - 1];
	int second_largest = -1;//assuming there is no second largest all same in array, single element in array, can be INT_MIN if negatives are also there, for now assuming only positives are there.
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] != largest) {
			second_largest = arr[i];
		}
	}
	return second_largest;
	// TC O(Nlogn)
	// SC O(1)
}

// Better

int print2largest(int arr[], int n) {
	// code here
	int _max = 0, second_max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > _max) {
			_max = arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > second_max and arr[i] != _max) {
			second_max = arr[i];
		}
	}
	return second_max;

	// two pass solution
	// tc o(n+n)
	// sc o(1)
}

// Optimal

int print2largest(int arr[], int n) {
	// code here
	// if the current element is max then whatever was the max previously will become the second largest
	// think of a case where second largest appears after the largest - 1 4 5 7 6
	// 6 appears after 7 which is largest, so we need to check if current element is lesser than largest so far
	// and if it is greater than second largest then we take it as second largest
	// TC - O(n)
	// SC - O(1)
	int _max = arr[0], second_max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > _max) {
			second_max = _max;
			_max = arr[i];
		}
		else if (arr[i] < _max and arr[i] > second_max) {
			second_max = arr[i];
		}
	}
	return second_max;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
	}
}

