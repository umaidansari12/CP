#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class Solution {
	priority_queue<int> max_heap_left;
	priority_queue<int, vector<int> , greater<int> > min_heap_right;
	double median = 0.0;
public:
	void insert(int x) {
		//cout << "Hello\n";
		if (max_heap_left.size() == min_heap_right.size()) {
			if (median < (double)x) {
				//if median is less than the current element so we will insert in right to maintain the sorted order
				min_heap_right.push(x);
				median = min_heap_right.top();

			} else if (median >= (double)x) {
				//if median is greter than or equal to the current element so we will insert in right to maintain the sorted order
				max_heap_left.push(x);
				median = max_heap_left.top();
			}
		}
		else if ((max_heap_left.size() + 1) == min_heap_right.size()) {
			if (median < x) {
				min_heap_right.push(x);
			}
			else if (median >= x) {
				min_heap_right.push(max_heap_left.top());
				max_heap_left.pop();
				max_heap_left.push(x);
			}
			median = (max_heap_left.top() + min_heap_right.top()) / 2.0;
		}
		else if (max_heap_left.size() == (min_heap_right.size() + 1)) {
			if (median < x) {
				max_heap_left.push(min_heap_right.top());
				min_heap_right.pop();
				min_heap_right.push(x);
			}
			else if (median >= x) {
				max_heap_left.push(x);
			}
			median = (max_heap_left.top() + min_heap_right.top()) / 2.0;
		}

	}
	double getMedian() {
		//cout << "Hello2\n";
		return median;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	//cout << t << endl;
	while (t--) {
		// int n, x;
		// cin >> n;
		//cout << n << endl;

		Solution* ob = new Solution();
		ob->insert(5);
		cout << ob->getMedian() << endl;
		ob->insert(15);
		cout << ob->getMedian() << endl;
		ob->insert(1);
		cout << ob->getMedian() << endl;
		ob->insert(3);
		cout << ob->getMedian() << endl;
		// for (int i = 0; i < n; i++) {
		// 	cin >> x;
		// 	//cout << x << endl;
		// 	ob.insert(x);
		// 	cout << ob.getMedian() << " ";
		// }
		cout << endl;

	}


	return 0;
}