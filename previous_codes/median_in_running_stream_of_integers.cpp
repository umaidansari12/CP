#include <bits/stdc++.h>
using namespace std;

class FindMedian
{
public:
	void insertHeap(int &);
	double getMedian();
private:
	double median; //Stores current median
	priority_queue<int> max; //Max heap for lower values
	priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
	void balanceHeaps(); //Method used by insertHeap
};

// Function to insert heap

//We can use a max heap on left side to represent elements that are less than effective
//median, and a min heap on right side to represent elements that are greater than
///effective median.
//After processing an incoming element, the number of elements in heaps differ utmost by 1
//element. When both heaps contain same number of elements, we pick average of heaps
//root data as effective median. When the heaps are not balanced, we select effective
// median from the root of heap containing more elements.

// Function to insert heap
void FindMedian::insertHeap(int &x)
{
	// insert in minheap or maxheap
	if (max.empty())
		max.push(x);
	else if (x > max.top())
		min.push(x);
	else if (min.empty())
	{
		min.push(max.top());
		max.pop();
		max.push(x);
	}
	else
		max.push(x);
	balanceHeaps();
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
	if (abs(max.size() - min.size()) > 1) //Heaps are not balanced
	{
		if (max.size() > min.size())
		{
			min.push(max.top());
			max.pop();
		}

		else
		{
			max.push(min.top());
			min.pop();
		}
	}
}

// Function to return getMedian
double FindMedian::getMedian()
{
	// if total size is even
	if ((max.size() + min.size()) % 2 == 0)
	{
		median = (max.top() + min.top());
		median /= 2;
	}
	else // if total size is odd
	{
		if (min.empty())
			median = max.top();
		else if (min.size() < max.size())
			median = max.top();
		else
			median = min.top();
	}

	return median;
}


void FindMedian::insertHeap(int &x)
{
	// Your code here
	if (max.empty() || x < max.top())
	{
		max.push(x);
	}
	else
	{
		min.push(x);
	}
	balanceHeaps();
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
	// Your code here
	if (max.size() > min.size() + 1)
	{
		min.push(max.top());
		max.pop();
	}
	else if (min.size() > max.size() + 1)
	{
		max.push(min.top());
		min.pop();
	}
}

// Function to return getMedian
double FindMedian::getMedian()
{
	// Your code here
	if (max.size() == min.size())
		median = (max.top() + min.top()) / 2;
	else if (max.size() > min.size())
		median = max.top();
	else
		median = min.top();
	return median;
}

class MedianFinder {
	priority_queue<int> mx;
	priority_queue<int, std::vector<int>, std::greater<int>> mn;
public:
	/** initialize your data structure here. */


	MedianFinder() {


	}
	void balance()
	{

		if (mx.size() > mn.size() + 1)
		{

			mn.push(mx.top());
			mx.pop();
		}
		else if (mn.size() > mx.size() + 1)
		{

			mx.push(mn.top());
			mn.pop();
		}
	}
	void addNum(int n) {
		if (mx.empty() || n < mx.top())
			mx.push(n);
		else
			mn.push(n);
		balance();

	}

	double findMedian() {
		if (mx.size() == mn.size())
			return double(mx.top() + mn.top()) / 2.0;
		else if (mx.size() > mn.size())
			return double(mx.top());
		return double(mn.top());
	}
};

int main()
{
	int n, x;
	int t;
	cin >> t;
	while (t--)
	{
		FindMedian Ans;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			Ans.insertHeap(x);
			cout << floor(Ans.getMedian()) << endl;
		}
	}
	return 0;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */