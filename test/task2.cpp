#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print(vector<float> a) {
	for (auto x : a)
		cout << x << " ";
	cout << endl;
}

void printHeap(priority_queue<float> max_heap) {
	while (max_heap.size() > 0) {
		cout << max_heap.top() << " ";
		max_heap.pop();
	}
	cout << endl;
}

int solution(vector<int> &A) {
	int _size = A.size(), filter_count_heap = 0, filter_count = 0;
	long long int sum = 0;
	priority_queue<float> max_heap;

	float curr_sum = 0;

	vector<float> B;

	for (int i = 0; i < _size; i++) {
		sum += A[i];
		max_heap.push(A[i]);
		B.push_back(A[i]);
	}



	float target_pollution = (float)sum / float(2.0);


	while (curr_sum < target_pollution) {
		filter_count_heap++;
		float in_sum = max_heap.top() / 2.0;
		curr_sum += (in_sum);
		max_heap.pop();
		max_heap.push(in_sum);
		printHeap(max_heap);
	}

	while (accumulate(B.begin(), B.end(), 0) > target_pollution) {
		filter_count++;
		int _max = max_element(B.begin(), B.end()) - B.begin();
		B[_max] /= 2.0;
		print(B);

	}
	return filter_count;
}


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		cout << solution(a) << endl;
	}
}