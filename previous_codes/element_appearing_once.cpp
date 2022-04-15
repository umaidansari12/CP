//Use binary search to find the answer

class Solution {
public:
	int search(int A[], int N) {
		//code
		int l = 0, h = N - 1;
		while (l <= h)
		{
			if (l == h)
				return A[l];
			int mid = (l + h) / 2;
			if (mid % 2 == 0)
			{
				if (A[mid] == A[mid + 1])
				{
					l = mid + 2;
				}
				else
				{
					h = mid;
				}
			}
			else
			{
				if (A[mid] == A[mid - 1])
				{
					l = mid + 1;
				}
				else
				{
					h = mid - 1;
				}
			}
		}

	}
};



class Solution1 {
public:
	int search1(int arr[], int low, int high)
	{
		if (low > high)
			return -1;

		if (low == high) {

			return arr[low];
		}

		int mid = (low + high) / 2;

		// If mid is even and element next to mid is
		// same as mid, then output element lies on
		// right side, else on left side
		if (mid % 2 == 0) {
			if (arr[mid] == arr[mid + 1])
				search1(arr, mid + 2, high);
			else
				search1(arr, low, mid);
		}

		// If mid is odd
		else {
			if (arr[mid] == arr[mid - 1])
				search1(arr, mid + 1, high);
			else
				search1(arr, low, mid - 1);
		}
	}
	int search(int arr[], int N) {
		//code
		return search1(arr, 0, N - 1);
	}
};

class Solution {
public:
	int bs(int *arr, int low, int high)
	{
		if (low == high)
		{
			return arr[low];
		}

		// Find the middle point
		int mid = (low + high) / 2;

		// If mid is even and element next to mid is
		// same as mid, then output element lies on
		// right side, else on left side
		if (mid % 2 == 0)
		{
			if (arr[mid] == arr[mid + 1])
				return bs(arr, mid + 2, high);
			else
				return bs(arr, low, mid);
		}
		else  // If mid is odd
		{
			if (arr[mid] == arr[mid - 1])
				return bs(arr, mid + 1, high);
			else
				return bs(arr, low, mid - 1);
		}
	}
	int search(int arr[], int n) {
		return bs(arr, 0, n - 1);
	}
};
