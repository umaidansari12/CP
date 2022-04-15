int peakElement(int arr[], int n)
{
	// Your code here
	for (int i = 0; i < n - 1; i++)
	{
		if ((arr[i - 1] <= arr[i]) && (arr[i + 1] <= arr[i]))
			return i;
	}
	return n - 1;
}