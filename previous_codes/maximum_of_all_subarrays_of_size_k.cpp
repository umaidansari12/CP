/*Try to solve this using window sliding technique. But, be aware, simple window sliding doesn't work.
You should think of some data structure to act as window of size K with some feature of getting max
of K elements in O(1) time.


We create a Deque, Qi of capacity k, that stores only useful elements of current window of k elements.
 An element is useful if it is in current window and is greater than all other elements on left side of
 it in current window. We process all array elements one by one and maintain Qi to contain useful elements of
  current window and these useful elements are maintained in sorted order. The element at front of the Qi is
  the largest and element at rear of Qi is the smallest of current window.

 */
class Solution {

public:
	vector <int> max_of_subarrays(int n, int *arr, int k) {
		vector <int> res;
		deque<int> q;

		int i = 0;
		for (i = 0; i < k; i++) {

			while ((!q.empty()) && (arr[i] >= arr[q.back()]))
				q.pop_back();

			q.push_back(i);

		}

		for (; i < n; i++) {

			res.push_back (arr[q.front()]);

			while ((!q.empty()) && (q.front() <= i - k)) q.pop_front();

			while ((!q.empty()) && (arr[i] >= arr[q.back()])) q.pop_back();

			q.push_back(i);

		}

		res.push_back (arr[q.front()]);
		q.pop_front();

		return res;
	}
};