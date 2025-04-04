#include <bits/stdc++.h>

using namespace std;

//input array is unsorted
// output array should be in sorted manner
// input array is sorted, and do'nt use any another data structure

int main() {
	int N, _max = 0;
	cin >> N;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		// _max = max(_max, arr[i]);
	}

	// vector<int> count(_max + 1, 0);
	map<int, int> count;

	for (int i = 0; i < N; i++) {
		count[arr[i]]++;
	}
	for (auto ele : count) {
		cout << ele.first << " - " << ele.second << "\n";
	}
	// for (int i = 0; i <= _max; i++) {
	// if (count[i] != 0)
	// cout << i << " ";
	// }
	cout << endl;

}

while (i < n(size of array))
(i + 1) < n and arr[i] != arr[i + 1]:
	temp.push_back(arr[i]);
else if ((i + 1) < n):
		temp.push_back(arr[i]);
	i++;


// [0, 0, 1, 1, 1, 2, 2, 3, 3, 3]
// temp.push_back(arr[i]);

// [0, 1, 2, 1, 1, 2, 2, 3, 3, 4]

	[0, 0, 1, 1, 2, 3, 4]

	temp = 0, 1, 2, 3,

	n = 7

	    i = 7


// current_element = arr[i];

// i = 5
//     j = 7

//         if arr[i] != arr[j]
// 	        arr[i + 1] = arr[j]
// 	                     i = j
// 	                         else
// 		                         j++;




