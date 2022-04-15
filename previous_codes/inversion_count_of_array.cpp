#include <bits/stdc++.h>

/*We need to make comparisons in the existing array and while doing any comparison,
we need to know how the two numbers being compared will be ordered in the sorted version of this array.
Can you use the algorithm of Merge Sort to achieve this task ?

Use Merge sort algorithm, and sort the array.
In merge function for merge sort, while comparing the elements,
if element in right array is smaller, then it is an inversion.
This means that this smaller element in the original array,
is behind larger elements. So add the number of larger elements or elements
left in the left-array, to the value of counter.

*/

using namespace std;
using ll = long long;

// counter to keep the count of inversion
long long my_counter = 0;

// Function to merge two parts of array
// p: initial point in the array, say left index
// q: mid point
// r: higher range
void merge(long long a[], long long p, long long q, long long r) {
	long long l = q - p + 1;
	long long a1[l];

	long long l2 = r - q;

	long long a2[l2];

	// storing elements on left half from a to a1
	for (long long i = 0; i < l; i++) {
		a1[i] = a[i + p];
	}

	// storing elements on right half from a to a2
	for (long long i = 0; i < l2; i++) {
		a2[i] = a[q + i + 1];
	}

	long long left = 0, right = 0, k = p;

	// merge while indexes are valid
	while (left < l && right < l2)
	{
		// comparing element of a1 and a2
		// and accordingly storing in a
		if (a1[left] <= a2[right]) {
			a[k] = a1[left];
			left++;
		}
		else {
			a[k] = a2[right];
			right++;

			// add the inversions that cross between
			// the first half and second half
			my_counter += (l - left); // Increementing counter
		}
		k++;
	}

	// store the rest elements
	while (left < l) {
		a[k++] = a1[left++];

	}

	// store the rest elements
	while (right < l2) {

		a[k++] = a2[right++];
	}
}

// Function to mergesort a[], which use
// divide and conquer for left and right mergesort
// operation
void mergeSort(long long a[], long long p, long long r)
{

	if (p < r)
	{
		// mid
		long long q = (p + r) / 2;

		// calling for left half
		mergeSort(a, p, q);

		// calling for right half
		mergeSort(a, q + 1, r);

		// after sorting, need to call merge funtion
		merge(a, p, q, r);
	}
}

// base function which calls the other utility function
// to find the number of inversions
long long int inversionCount(long long A[], long long N)
{
	mergeSort(A, 0, N - 1);
	long long int res = my_counter;
	my_counter = 0;
	return res;
}



using namespace std;
using ll = long long;

void bruteforce(vector<int> &a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				count++;
		}
	}
	cout << count << endl;
}

void multi_set_method(vector<int> &a, int n)
{
	multiset<int> s;
	int count = 0;
	s.insert(a[0]);
	for (int i = 1; i < n ; i++)
	{
		s.insert(a[i]);
		int dist = distance(s.upper_bound(a[i]), s.end());
		count += dist;
	}

	cout << count << endl;

}

long long int merge(vector<int>&a, vector<int>&temp, int left, int mid, int right)
{
	long long int invcount = 0, i, j, k;
	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right))
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			invcount += (mid - i);
		}

	}
	while (i <= mid - 1)
		temp[k++] = a[i++];
	while (j <= right)
		temp[k++] = a[j++];
	for (int i = left; i <= right; i++)
	{
		a[i] = temp[i];
	}
	return invcount;

}

long long int mergeSortmethod(vector<int>&a, vector<int>&temp, int left, int right)
{
	long long int mid, invcount = 0;
	if (right > left)
	{
		mid = (left + right) / 2;
		invcount += mergeSortmethod(a, temp, left, mid);
		invcount += mergeSortmethod(a, temp, mid + 1, right);
		invcount += merge(a, temp, left, mid + 1, right);
	}
	return invcount;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n), temp(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << mergeSortmethod(a, temp, 0, n - 1) << endl;

	}


	return 0;
}