/*Create and maintain MaxHeap of size k.
While inserting elements in heap keep check whether size of heap is less than k. If size of heap becomes k and tompost element of heap is more than kth(index starting from 0) element of array then remove the tompost element and insert current element of array.
Do this while i < n. Finally print the topmost element of heap.*/

int kthSmallest(int arr[], int n, int k) {

	priority_queue<int, vector<int>> pq;

	for (int i = 0; i < n; i++) {
		if (pq.size() == k) { // if size becomes equal to k
			if (pq.top() > arr[i]) { // if top element is larger than arr[i]
				pq.pop();
				pq.push(arr[i]);
			}
		}
		else if (pq.size() < k) {
			pq.push(arr[i]);
		}
	}

	return pq.top(); // returns kth smallest element
}

int kthSmallest(int arr[], int l, int r, int k) {
	//code here
	// sort(arr,arr+r+1);
	//return arr[k-1];
	priority_queue<int, vector<int>, greater<int> > p;
	for (int i = 0; i <= r; i++)
		p.push(arr[i]);
	int ans = INT_MIN;
	while (k--)
	{
		ans = p.top();
		p.pop();
	}
	return ans;
}