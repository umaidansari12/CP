//Initial Template for C++

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int a[n] , i;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		rotate(a, n);
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
// } Driver Code Ends


//User function Template for C++

/*Following are steps.
1) Store last element in a variable say x.
2) Shift all elements one position ahead.
3) Replace first element of array with x.*/

void rotate(int arr[], int n)
{
	int temp = arr[n - 1];
	for (int i = n - 1; i >= 1; i--)
		arr[i] = arr[i - 1];
	arr[0] = temp;
}



void rotate(int arr[], int n)
{
	int a[n];
	for (int i = 0; i < n; i++)
		a[(i + 1) % n] = arr[i];
	for (int i = 0; i < n; i++)
		arr[i] = a[i];
}